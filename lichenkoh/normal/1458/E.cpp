#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
template<typename T> int bins(vector<T> const&v,T const& key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
template<typename T> bool hasbins(vector<T> const& v,T const& key) {int i=bins(v,key); return i<v.size() && v[i]==key;}
template<typename Key, typename Val> class PreMap {
public:
  vector<Key> vkey;
  vector<Val> vval;
  void addKey(Key key) {
    vkey.PB(key);
  }
  void init() {
    makeunique(vkey);
    vval.resize(vkey.size());
  }
  void init(Val const& val) {
    makeunique(vkey);
    vval.resize(vkey.size(),val);
  }
  void initWithVkey(vector<Key> const& invkey) {
    vkey=invkey;
    vval.resize(vkey.size());
  }
  void initWithVkey(vector<Key> const& invkey, Val const& val) {
    vkey=invkey;
    vval.resize(vkey.size(),val);
  }
  int geti(Key const& k) {
    return bins(vkey,k);
  }
  Val operator [](Key const& k) const {
    return vval[bins(vkey,k)];
  }
  Val & operator [](Key const& k) {
    return vval[bins(vkey,k)];
  }
  int size() const {return vkey.size();}
};

const bool DBG=0;
const bool LOSE=0,WIN=1;
vector<bool> vfinal;
map<int,pair<vi,vpii> > hlen2x;
int hix=0,hiy=0;
set<int> sx,sy;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,qn; cin>>n>>qn;
  vfinal.resize(qn);
  hlen2x[0].fst.PB(0);
  for (int ti=0;ti<n;ti++) {
  	int x,y; cin>>x>>y; hlen2x[x+y].fst.PB(x);
  }
  for (int qi=0;qi<qn;qi++) {
  	int x,y; cin>>x>>y; hlen2x[x+y].snd.PB(MP(x,qi));
  }
  for (auto &w:hlen2x) {
  	int len=w.fst;
    //printf("len:%d old hix:%d hiy:%d\n",len,hix,hiy);
  	vi &v=w.snd.fst;
  	if (len>0) {
      while(sx.count(hix)) hix++;
      while(sy.count(hiy)) hiy++;
      while(hix+hiy<len) {
        int dx=INF,dy=INF;
        auto xit=sx.upper_bound(hix);
        if (xit!=sx.end()) dx=*xit-hix;
        auto yit=sy.upper_bound(hiy);
        if (yit!=sy.end()) dy=*yit-hiy;
        int go=min(max(1,(len-hix-hiy)/2),min(dx,dy));
        //printf("hix:%d hiy:%d go:%d len-hix-hiy:%d dx:%d dy:%d\n",hix,hiy,go,
        //  len-hix-hiy,dx,dy);
        hix+=go;
        hiy+=go;
        while(sx.count(hix)) hix++;
        while(sy.count(hiy)) hiy++;
      }
      if (hix+hiy==len) {
        //printf("hix:%d hiy:%d\n",hix,hiy);
        v.PB(hix);
      }
  	}
  	sort(v.begin(),v.end());
  	for (auto &x: v) {
      //printf("sx push: %d sy push:%d\n",x,len-x);
  		sx.insert(x); sy.insert(len-x);
  	}
  	for (auto &xq:w.snd.snd) {
			vfinal[xq.snd]=hasbins(v,xq.fst)?LOSE:WIN;
  	}
  }
  for (int qi=0;qi<qn;qi++) {
  	printf((vfinal[qi]==WIN)?"WIN\n":"LOSE\n");
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