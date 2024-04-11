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


class RangeSegTree {
public:
  int segn=-1;
  using S=ll;
  vector<S> t;
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void init(int n) {
    segn=n; t.resize(2*segn); for (int i=0;i<2*segn;i++) t[i]=identity;
  }
  void modify(int l, int r, const S& value) {
    if (l>r) return;
    r++;
    int n=segn;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        t[l] = combine(t[l], value);
        l++;
      }
      if (r&1) {
        --r;
        t[r] = combine(t[r], value);
      }
    }
  }

  S query(int p) {
    int n=segn;
    S res = identity;
    for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
    return res;
  }
  void push() {
    int n=segn;
    for (int i = 1; i < n; ++i) {
      t[i<<1] = combine(t[i<<1], t[i]);
      t[i<<1|1] = combine(t[i<<1|1], t[i]);
      t[i] = identity;
    }
  }
};



const ll INF=1LL<<60;
struct Data{
  vector<pll> s[2];
  RangeSegTree seg[2];
  Data(int n) {
    for (ll idx=0;idx<2;idx++) {
      s[idx].PB(MP(INF,-INF));
      seg[idx].init(n);
    }
  }
  void push(ll idx, pll p) {
    auto &v=s[idx];
    while(v.size() > 0 && v.back().snd + seg[idx].query(int(v.size())-1) >= p.snd) {
      int last=int(v.size())-1;
      if (last>=0) {
        seg[idx].modify(last,last, -seg[idx].query(last));
      }
      v.pop_back();
    }
    v.PB(p);
  }
  void addbase(ll idx, ll val) {
    int last=int(s[idx].size())-1;
    if (last>=0) {
      seg[idx].modify(0,last, val);
    }
  }
  pll findleq(ll idx, ll key) {
    auto &v=s[idx];
    ll imin=0,imax=v.size();
    while(imin<imax) {
      ll imid=(imin+imax)/2;
      if (v[imid].snd  + seg[idx].query(imid) <= key) imin=imid+1;
      else imax=imid;
    }
    pll ans=v[imin-1];
    ans.snd += seg[idx].query(imin-1);
    return ans;
  }
  void pr() {
    for (ll idx=0;idx<2;idx++) {
      auto &v=s[idx];
      printf("idx:%lld v: ",idx);
      for (int i=0;i<v.size();i++) {
        auto &w=s[idx][i];
        printf(" (pos:%lld, val:%lld, seg:%lld) ", w.fst,w.snd,seg[idx].query(i));
      }
      printf("\n");
    }
  }
};
void go() {
  ll n; cin>>n;
  vll vans(n+1);
  vll a(n);
  for (int i=0;i<n;i++) cin>>a[i];
  Data d(n+1);
  for (ll x=n-1;x>=0;x--) {
    d.addbase(x%2, a[x]);
    d.addbase((x+1)%2, -a[x]);
    //d.pr();
    pll got1=d.findleq(x%2, 0);
    pll got2=d.findleq((x+1)%2, 0);
    //printf("x:%lld got1 pos:%lld val:%lld got2 pos:%lld val:%lld\n",x,got1.fst,got1.snd,got2.fst,got2.snd);
    pll got=min(got1,got2);
    if (a[x]==0) {
      vans[x] = 1+vans[x+1];
    } else {
      if (got.snd==0) {
        vans[x] = 1+vans[got.fst+1];
      }
    }
    d.push(x%2, MP(x,a[x]));
  }
  ll final=0;
  for (auto &y:vans) final+=y;
  printf("%lld\n",final);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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