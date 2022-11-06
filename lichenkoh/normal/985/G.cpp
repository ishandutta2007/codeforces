#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,unsafe-math-optimizations")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
#include <immintrin.h>
#include <emmintrin.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef unsigned int uint;
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
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
const int mn=200000+1;
vi g[mn];
int bins(vector<int> &v, int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
  
}

bool binf(vector<int> &v, int key) {
  int imin=bins(v,key);
  return (imin<v.size()) && (v[imin]==key);
}

ll C2(ll x) {
  ll a=x,b=x-1;
  if (a&1) b/=2;
  else a/=2;
  return a*b;
}
#define tm tmm
const int L=0,M=1,R=2;
uint tri[mn][3];
uint C[3];
uint vlo[mn],vhi[mn];
uint tl[mn],tm[mn],tr[mn];
ll ans[3];
const int ms=4000;
int x2s[mn];
bitset<mn> b[ms];
pii vs[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<3;i++) C[i]=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y);
    g[y].PB(x);
    vlo[max(x,y)]++;
    vhi[min(x,y)]++;
  }
  for (int x=0;x<n;x++) vs[x]=MP(g[x].size(),x);
  sort(vs,vs+n,greater<pii>());
	int slim=min(n,ms);
	memset(x2s,-1,sizeof x2s);
	for (int s=0;s<slim;s++) {
		int x=vs[s].snd; x2s[x]=s;
		for (auto &y:g[x]) b[s][y]=true;
	}
  for (int x=0;x<n;x++) sort(g[x].begin(),g[x].end());
  for (int x=0;x<n;x++) {
    for (auto &y:g[x]) {
    	uint lt=bins(g[y],x);
    	uint gt=g[y].size()-lt-1;
      if (y<x) {
        tl[x]+=lt;
        tm[x]+=gt;
      }
      else {
        tr[x]+=gt;
        tm[x]+=lt;
      }
    }
  }
	for (int xx=0;xx<n;xx++) {
    for (auto &yy:g[xx]) {
      if (xx>yy) continue;
      int x=xx,y=yy;
      if (g[x].size()>g[y].size()) swap(x,y);
      //assert(g[x].size()<=g[y].size());
      int s=x2s[y];
      if (s==-1) {
      	for (auto &z:g[x]) {
      	  if (binf(g[y],z)) {
      	    int state;
      	    if (z>x&&z>y) state=R;
      	    else if (z<x&&z<y) state=L;
      	    else state=M;
      	    ++tri[z][state];
      	  }
      	}
      }
      else {
      	for (auto &z:g[x]) {
      	  if (b[s][z]) {
      	    int state;
      	    if (z>x&&z>y) state=R;
      	    else if (z<x&&z<y) state=L;
      	    else state=M;
      	    ++tri[z][state];
      	  }
      	}
      }
    }
  }
  int el=0,er=m;
  for (int x=0;x<n;x++) {
    er-=vhi[x];
    ll em=m-el-er-g[x].size();
    // Code goes here
    ll al=x,ar=n-x-1;
    ll bl=vlo[x],br=vhi[x];
    ll gl=al-bl,gr=ar-br;
    { // x is leftmost
      ll one=br*gr+C2(br)+er;
      ll two=tr[x];
      ll three=tri[x][L];
      ll contrib=one-two+three;
      ll all=C2(ar);
      ans[L]+=(all-contrib)*x;
    }
    { // x is on rightmost
      ll one=bl*gl+C2(bl)+el;
      ll two=tl[x];
      ll three=tri[x][R];
      ll contrib=one-two+three;
      ll all=C2(al);
      ans[R]+=(all-contrib)*x;
    }
    { // mid x
      ll one=bl*gr+gl*br+bl*br+em;
      ll two=tm[x];
      ll three=tri[x][M];
      ll contrib=one-two+three;
      ll all=al*ar;
      ans[M]+=(all-contrib)*x;
    }
    // Ends here
    el+=vlo[x];
  }
  ll final=0;
  for (int i=0;i<3;i++) final+=ans[i]*C[i];
  printf("%llu\n",final);
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