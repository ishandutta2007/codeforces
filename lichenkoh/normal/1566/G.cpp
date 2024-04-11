#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

inline ll MK(int x, int y) {if (x>y) swap(x,y); return (ll(x)<<32)|y;}
const int me=200000;
const int mn=100000;
int deg[mn];
int rawX[me],rawY[me],rawW[me],rawbirth[me],rawdeath[me];
int X[me],Y[me],W[me],qbirth[me],qdeath[me];
const int plim=316;
//const int plim=2;
bitset<me> allb;
bitset<me> b[plim];
vi birth[mn+1],death[mn+1];
set<int> s[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(rawdeath,0x7f,sizeof rawdeath);
  int n=rint(); int m=rint();
  map<ll,int> h;
  int raw=0;
  for (;raw<m;raw++) {
  	int x=rint()-1; int y=rint()-1;
  	rawX[raw]=x; rawY[raw]=y;
  	h[MK(x,y)]=raw;
  	rawW[raw]=rint();
  }
  int limts=rint();
  {
  	for (int ts=1;ts<=limts;ts++) {
  		int type=rint(); int x=rint()-1; int y=rint()-1;
  		if (type==0) {
  			int oldraw=h[MK(x,y)];
  			rawdeath[oldraw]=ts;
  		} else {
  			rawbirth[raw]=ts;
		  	rawX[raw]=x; rawY[raw]=y;
  			h[MK(x,y)]=raw;
  			rawW[raw]=rint();
  			raw++;
  		}
  	}
  }
  vi vsort(raw);
  for (int r=0;r<raw;r++) {
  	vsort[r]=r;
  }
  sort(vsort.begin(),vsort.end(), [&](int const x, int const y){return tie(rawW[x],x) < tie(rawW[y],y);});
  for (int id=0;id<raw;id++) {
  	int r=vsort[id];
  	int x=X[id]=rawX[r]; ++deg[x];
  	int y=Y[id]=rawY[r]; ++deg[y];
  	W[id]=rawW[r];
  	birth[rawbirth[r]].PB(id);
  	int d=rawdeath[r];
  	if (d<INF) death[d].PB(id);
  	qbirth[id]=rawbirth[r];
  	qdeath[id]=d;
  }
  vsort.resize(n);
  for (int x=0;x<n;x++) vsort[x]=x;
  sort(vsort.begin(),vsort.end(), [&](int const x, int const y){return tie(deg[x],x) > tie(deg[y],y);});
	vi invVertex(n); for (int x=0;x<n;x++) invVertex[vsort[x]]=x;
	for (int id=0;id<raw;id++) {
		X[id]=invVertex[X[id]];
		Y[id]=invVertex[Y[id]];
	}
	for (int x=0;x<plim;x++) b[x].set();
	set<int> alle;
  for (int ts=0;ts<=limts;ts++) {
  	for (int e:birth[ts]) {
  		allb[e]=true;
  		alle.insert(e);
  		int x=X[e];
  		if (x<plim) {b[x][e]=false;} 
  		s[x].insert(e);
  		int y=Y[e];
  		if (y<plim) {b[y][e]=false;} 
  		s[y].insert(e);
  	}
  	for (int e:death[ts]) {
  		allb[e]=false;
  		alle.erase(e);
  		int x=X[e];
  		if (x<plim) {b[x][e]=true;} 
  		s[x].erase(e);
  		int y=Y[e];
  		if (y<plim) {b[y][e]=true;} 
  		s[y].erase(e);
  	}
		int loe=*(alle.begin());
		int x=X[loe],y=Y[loe];
		if (x>y) swap(x,y);
		ll final=LLONG_MAX;
		{
			int e=INF;
			if (y<plim) {
				e=(allb&b[x]&b[y])._Find_first();
			} else if (x<plim) {
				auto bx=allb&b[x];
				e=bx._Find_first();
				while (e < raw) {
					if(s[y].count(e)) {
						e=bx._Find_next(e);
					} else break;
				}
			} else {
				for (int i:alle) {
					if (!(s[x].count(i)||s[y].count(i))) {
						e=i; break;
					}
				}
			}
			if (e<raw) {
				ll cand=W[e]+W[loe];
				chkmin(final,cand);
			}
		}
		if (s[x].size()>=2 && s[y].size()>=2) {
			int cx=0,cy=0;
			for (auto ix=++s[x].begin();cx<2&&ix!=s[x].end();++ix,++cx) {
				int ox=X[*ix]; if (ox==x) ox=Y[*ix];
				for (auto iy=++s[y].begin();cy<2&&iy!=s[y].end();++iy,++cy) {
					int oy=X[*iy]; if (oy==y) oy=Y[*iy];
					if (ox!=oy && ox!=y && oy!=x) {
						ll cand=W[*ix]+W[*iy];
						chkmin(final,cand);
					}
				}
			}
		}
		for (int t=0;t<2;t++) {
			if (s[x].size()>=3) {
				auto it=s[x].begin();
				ll cand=0;
				for (int i=0;i<3;i++) {
					cand+=W[*it];
					++it;
				}
				chkmin(final,cand);
			}
			swap(x,y);
		}
		printf("%lld\n",final);
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