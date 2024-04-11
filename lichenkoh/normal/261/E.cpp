#include <bits/stdc++.h>
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
const int ms=735425;
vector<int> vp={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<int> vq={53,59,61,67,71,73,79,83,89,97};
const int LIM=1000*1000*1000;
int f[ms];
const int mk=100;
bool notok[mk];
char g[ms][mk];
const int LOGDIV=5;
const int DIV=1<<LOGDIV;
const int mh=(LIM/DIV)+2;
int h[mh];
void gen() {
	for (auto &q:vq) notok[q]=true;
	f[0]=1;
	int sz=1;
	int nsz=sz;
	for (auto &p:vp) {
		for (int i=0;i<sz;i++) {
			int x=f[i];
			while(1) {
				if (__builtin_smul_overflow (x, p, &x)) break;
				if (x>LIM) break;
				f[nsz]=x;
				++nsz;
			}
		}
		sz=nsz;
	}
	sort(f,f+ms);
	for (int i=0;i<ms;i++) {
		int x=f[i];
		//if (x==1005048) printf("GOT\n");
		h[(x>>LOGDIV)+1]=i+1;
	}
	int best=h[0];
	for (int i=1;i<mh;i++) {
		if (h[i]>best) best=h[i];
		else h[i]=best;
	}
	memset(g,127,sizeof g);
	memset(g[0],0,sizeof g[0]);
	for (int xi=0;xi<ms;xi++) {
		int x=f[xi];
		char has=127;
		for (int k=2;k<mk;k++) {
			if (g[xi][k]<has) has=g[xi][k];
			else g[xi][k]=has;
		}
		for (int y=x+x,k=2;y<=LIM&&k<mk;y+=x,k++) {
			if (notok[k]) continue;
			char have=g[xi][k];
			if (have==127) continue;
			//if (y==3) printf("x:%d have:%d y:%d k:%d\n",x,have,y,k);
			int ydiv=y>>LOGDIV;
			int imin=h[ydiv],imax=h[ydiv+1];
			//printf("y:%d ydiv:%d imin:%d imx:%d x:%d k:%d\n",y,ydiv,imin,imax,x,k); fflush(stdout);
			while(imin<imax) {
				int imid=(imin+imax)>>1;
				if (f[imid]<y) imin=imid+1;
				else imax=imid;
			}
			chkmin(g[imin][k],(char)(have+(char)1));
		}
	}
}
const int mt=1169;
ll vlarge[mt];
void gen2() {
	vlarge[0]=(((ll)1)<<32)|(1<<16)|0;
	int sz=1;
	int nsz=sz;
	for (auto &p:vq) {
		for (int i=0;i<sz;i++) {
			int x=vlarge[i]>>32;
			//printf("x:%d p:%d vlarge[i]:%lld\n",x,p,vlarge[i]);
			int cnt=vlarge[i]&0xffff;
			while(1) {
				if (__builtin_smul_overflow (x, p, &x)) break;
				if (x>LIM) break;
				++cnt;
				vlarge[nsz]=(((ll)x)<<32)|(p<<16)|cnt;
				++nsz;
			}
		}
		sz=nsz;
	}
	//printf("sz:%d\n",sz);
	sort(vlarge,vlarge+mt);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int l,r,allsteps; scanf("%d%d%d\n",&l,&r,&allsteps);
  gen();
  gen2();
  int ans=0;
  //set<int> tmp;
  for (int xi=0;xi<ms;xi++) {
  	int x=f[xi];
  	for (int yi=0;yi<mt;yi++) {
  		ll got=vlarge[yi];
  		int val=got>>32;
  		int y;
  		if (__builtin_smul_overflow(x,val,&y)) break;
  		if (y>r) break;
  		if (y<l) continue;
  		int lft=got&0xffffffff;
  		int p=lft>>16;
  		int cnt=lft&0xffff;
  		for (int k=p;k<mk;k++) {
  			//if (y==106) printf("x:%d k:%d g:%d cnt:%d\n",x,k,(int)g[xi][k],cnt);
  			if (cnt+(int)g[xi][k]+k<=allsteps) {
  				//printf("x:%d y:%d cnt:%d g:%d k:%d\n",x,y,cnt,(int)g[xi][k],k);
  				//printf("y:%d\n",y);
  				//tmp.insert(y);
  				ans++; break;
  			}
  		}
  	}
  }
  printf("%d\n",ans);
  //for (auto &w:tmp) printf("%d\n",w);
}