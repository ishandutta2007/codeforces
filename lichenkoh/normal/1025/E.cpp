#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=52;
bitset<mn> b[mn];
pii src[mn][mn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,k;
pair<bool,vector<pair<pii,pii> > > bfs(int sx, int sy, int tx, int ty) {
	b[0].set(); b[n+1].set();
	for (int x=1;x<=n;x++) b[x][n+1]=b[x][0]=true;
//	printf("BFS %d %d -> %d %d\n",sx,sy,tx,ty); fflush(stdout);
	queue<pii> q;
	q.push(MP(sx,sy));
	while(!q.empty()) {
		auto got=q.front(); q.pop();
		int x=got.fst,y=got.snd;
		b[x][y]=true;
		if (got==MP(tx,ty)) {
			vector<pair<pii,pii> > vans;
			while(got!=MP(sx,sy)) {
				pii from=src[got.fst][got.snd];
				vans.PB(MP(from,got));
				got=from;
			}
			reverse(vans.begin(),vans.end());
			return MP(true, vans);
		}
		for (int d=0;d<4;d++) {
			int nx=x+dx[d],ny=y+dy[d];
			if (!b[nx][ny]) {
	//			printf("%d %d -> nx:%d ny:%d\n",x,y,nx,ny); fflush(stdout);
				b[nx][ny]=true;
				src[nx][ny]=MP(x,y);
				q.push(MP(nx,ny));
			}
		}
	}
	return MP(false,vector<pair<pii,pii> >());
}
const int lim=10800;
pair<bool,vector<pair<pii,pii> > > go(vpii s, vpii t) {
	vector<pair<pii,pii> > vans;
	bitset<mn> used; used.reset();
	while(s!=t) {
		if (used.count()==k) return MP(true,vans);
		vector<pair<pii,pii> > best; int besti=-1;
		for (int q=0;q<k;q++) {
			if (!used[q]) {
				for (int x=1;x<=n;x++) b[x].reset();
				for (int i=0;i<q;i++) {auto w=s[i]; b[w.fst][w.snd]=true;}
				for (int i=q+1;i<k;i++) {auto w=s[i]; b[w.fst][w.snd]=true;}
				auto got=bfs(s[q].fst, s[q].snd, t[q].fst, t[q].snd);
				if (got.fst&&(besti==-1||got.snd.size()<best.size())) {
					best=got.snd;
					besti=q;
				}
			}
		}
	//	printf("besti:%d\n",besti);
		if (besti==-1) {
		//	printf("RET\n");
			return MP(false,vector<pair<pii,pii> >());
		}
		{
			int q=besti;
			used[q]=true;
			s[q]=t[q];
			for (auto &w:best) vans.PB(w);
			if (vans.size()>lim) return MP(false,vector<pair<pii,pii> >());
		}
	}
	return MP(true,vans);
}

pair<bool,vector<pair<pii,pii> > > bf(vpii s, vpii t) {
	vector<pair<pii,pii> > vans;
	srand(__builtin_ia32_rdtsc()&0xffff);
	for (int i=0;i<lim;i++) {
		if (s==t) return MP(true, vans);
		int r=rand()%k;
		pii got=s[r];
		while(1) {
			int d=rand()%4;
			int nx=got.fst+dx[d]; int ny=got.snd+dy[d];
			if (1<=nx&&nx<=n && 1<=ny&&ny<=n) {
				pii nxt=MP(nx,ny);
				bool ok=1;
				for (auto &w:s) {
					if (w==nxt) {ok=0; break;}
				}
				if (ok) {
					//printf("r:%d d:%d. %d %d -> %d %d\n",r,d,got.fst,got.snd,nx,ny);
					vans.PB(MP(got,nxt));
					s[r]=nxt;
					break;
				}
			}
		}
	}
	return MP(false,vector<pair<pii,pii> >());
}
void out(vector<pair<pii,pii> > vans) {
	printf("%d\n",(int)vans.size());
	for (auto &w:vans) {
		printf("%d %d %d %d\n",w.fst.fst,w.fst.snd,w.snd.fst,w.snd.snd);
	}
	exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); k=rint();
  vpii a[2];
  for (int t=0;t<2;t++) for (int i=0;i<k;i++) {
  	int x=rint(); int y=rint();
  	a[t].PB(MP(x,y));
  }
  vpii t;
  for (int i=1;i<=k;i++) t.PB(MP(i,1));
  for (int asd=0;asd<2;asd++) {
  	for (int qwe=0;qwe<2;qwe++) {
  		//printf("asd:%d qwe:%d\n",asd,qwe);
  		auto got1=go(a[0],t);
  		auto got2=go(a[1],t);
  		if (got1.fst&&got2.fst&&got1.snd.size()+got2.snd.size()<=lim) {
  			reverse(got2.snd.begin(),got2.snd.end());
  			for (auto &w:got2.snd) {
  				got1.snd.PB(MP(w.snd,w.fst));
  			}
  			out(got1.snd);
  		}
  		for (int i=0;i<k;i++) swap(t[i].fst,t[i].snd);
  	}
  	for (int i=0;i<k;i++) t[i].snd=n;
  }
//assert(0);
	while(1) {
  		auto got=bf(a[0],a[1]);
  		if (got.fst) {
  			out(got.snd);
  		}
	}




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