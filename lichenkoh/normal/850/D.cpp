#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
//const int mv=300;
const int mv=160;
const int mc=((mv*(mv-1))/2)+1;
const int ma=31;
bitset<mc> f[mv][ma];
void reset() {
	for (int v=0;v<mv;v++) for (int ai=0;ai<ma;ai++) f[v][ai].reset();
}
vector<int> solve(vector<int> &a) {
	vector<int> fail;
	sort(a.begin(),a.end());
	int alim=a.size();
	/*if (alim==1) {
		if (a[0]==0) {
			return vector<int>({0});
		}
		else return fail;
	}*/
	f[0][0][a[0]]=true;
	{
		int v=0;
		int klim=(v*(v+1))/2;
		if (f[(v)][alim-1][klim]) {
			return vector<int>({a[0]});
		}
	}
	for (int v=1;v<mv;v++) {
		//for (int ai=0;ai<alim;ai++) {
		//	f[(v)][ai].reset();
		//}
		for (int sai=0;sai<alim;sai++) {
			for (int dai=sai;dai<=min(alim-1,sai+1);dai++) {
				int shift=a[dai];
				f[(v)][dai]|=(f[(v)-1][sai]<<shift);
			}
		}
		int klim=(v*(v+1))/2;
		if (f[(v)][alim-1][klim]) {
			vector<int> final;
			int ai=alim-1;
			int k=klim;
			//printf("DBG:%d\n",(int)f[2][1][4]);
			for (int x=v;x>=1;x--) {
				//printf("x:%d k:%d ai:%d sub:%d\n",x,k,ai,k-a[ai]);
				//printf("help:%d %d %d. %d, %d\n",x-1,ai,k-a[ai],(int)f[x-1][ai][k-a[ai]],
				//	(int)((k-a[ai]>=0)&&f[x-1][ai][k-a[ai]]));
				//fflush(stdout);
				final.PB(a[ai]);
				k-=a[ai];
				//assert(k>=0);
				if (f[x-1][ai][k]) {
					ai=ai;
				}
				else {
					//assert(ai-1>=0&&f[x-1][ai-1][k]);
					ai--;
				}
			}
			final.PB(a[0]);
			sort(final.begin(),final.end());
			return final;
		}
		bitset<mc> filt; filt.set(); filt>>=klim; filt<<=klim;
		for (int ai=0;ai<alim;ai++) {
			f[(v)][ai]&=filt;
		}
	}
	return fail;
}
bool vans[mv+2][mv+2];
void recurse(vector<int> &r) {
	//sort(r.begin(),r.end());
	//vector<int> copy=r;
	//sort(copy.begin(),copy.end()); assert(r==copy);
	int n=r.size()-1;
	if (n==0) return;
  vector<int> R;
  R.PB(-1);
  int sum=0;
  for (int i=1;i<=n;i++) {
  	sum+=r[i];
  	R.PB(sum);
  }
	int s=n-1-r[n];
	vector<int> F; F.resize(n+1);
	for (int v=1;v<=n;v++) F[v]=R[v]-(v*(v-1))/2;
	int j=1;
	vector<int> rp=r;
	for (int x=1;x<=n;x++) vans[n][x]=1;
	vans[n][n]=0;

	/*for (auto &w:r) printf("%d ",w); printf(" end r\n");
	for (auto &w:R) printf("%d ",w); printf(" end R\n");
	for (auto &w:F) printf("%d ",w); printf(" end F\n");
	for (int v=1;v<=n;v++) assert(F[v]>=0);*/
	//assert(F[n]==0);
	vector<int> vj; vj.resize(s+1);
	for (int d=1;d<=s;d++) {
		int vmin=max(1,vj[d-1]+1);
		int ans=vmin;
		for (int v=n-1;v>=vmin;v--) {
			if (F[v]<d) {
				ans=v+1;
				break;
			}
		}
		//printf("d:%d ans:%d n:%d\n",d,ans,n); fflush(stdout);
		vj[d]=ans;
	}
	for (int d=1;d<=s;d++) {
		int j=vj[d];
		assert(j<=n-1);
		vans[n][j]=0;
		vans[j][n]=1;
		rp[j]--;
	}
	rp.resize(rp.size()-1);
	recurse(rp);
}
vector<int> fgot;
int comb(vector<int> &va) {
  auto got=solve(va);
  fgot=got;
  if (got.size()==0) {
  	printf("=(\n");
  	return 0;
  }
  else {
  	vector<int> r;
  	r.PB(-1);
  	for (auto &w:got) r.PB(w);
  	recurse(r);
  	int sz=got.size();
  	printf("%d\n",sz);
  	for (int x=1;x<=sz;x++) {
  		for (int y=1;y<=sz;y++) {
  			printf("%d",(int)vans[x][y]);
  		}
  		printf("\n");
  	}
  	return sz;
  }
}

void test() {
	reset();
	memset(vans,0,sizeof vans);
	//vector<int>va={1,4};
	//if (rand()&1) va={0,3};
	vector<int>va;
	int p=(rand()%100);
	for (int x=0;x<=30;x++) {
		if (rand()%100 <= p) va.PB(x);
	}
	if (va.size()==0) va.PB(rand()%31);
	//for (auto &w:va) printf("%d ",w); printf(" va\n"); fflush(stdout);
	int got=comb(va);
	if (got!=0) {
		set<int> s;
		for (int x=1;x<=got;x++) {
			assert(vans[x][x]==0);
			int degout=0;
			for (int y=1;y<=got;y++) {
				degout+=vans[x][y];
			}
			s.insert(degout);
		}
		for (int x=1;x<=got;x++) {
			for (int y=1;y<=got;y++) {
				if (x==y) continue;
				assert(vans[x][y]+vans[y][x]==1);
			}
		}
		set<int> sa; for (auto &w:va) sa.insert(w);
		if(s!=sa){
			for (auto &w:sa) printf("%d ",w); printf(" sa\n");
			for (auto &w:s) printf("%d ",w); printf(" s\n");
			for (auto &w:fgot) printf("%d ",w); printf(" fgot\n");
			exit(1);
		}
	}
}
void go() {
	for (int k=0;k<100000;k++) {
		srand(clock());
		test();
	}
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go();
  int n=rint(); vector<int> va; va.reserve(n);
  for (int i=0;i<n;i++) {
  	int x=rint(); va.PB(x);
  }
  comb(va);
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}