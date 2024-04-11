#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


template<int _SEGSZ> class RangeSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
  S t[2 * SEGSZ];
  S identity = INT_MIN;
  S combine(const S& lefts, const S& rights) {
    return max(lefts,rights);
  }
  void init(int n) {
    segn=n;
    for (int i=0;i<=2*n;i++) t[i]=identity;
  }
  void modify(int l, int r, const S& value) {
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

const int mn = (1e6) + 4;
RangeSegTree<mn> seg;

vector<char> go(string s) {
  int n=s.length();
  seg.init(n+1);
  vector<vector<int>> p(2,vector<int>(n,0));
  for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) {
    for(int i=0;i<n;i++) {
      if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
      int L=i-p[z][i], R=i+p[z][i]-!z;
      while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
      if(R>r) l=L,r=R;
    }
  }
  int k=0;
  for (int l=0;l<n;l++) {
    int r=n-1-l;
    if (l<r && s[l]==s[r]) {
      k++;
    } else break;
  }

  for (int z=0;z<2;z++) {
    for (int x=0;x<n;x++) {
      int pal=p[z][x];
      //printf("z:%d x:%d p:%d\n",z,x,pal);
      if (z==0) { // Centered at x-1|x
        int l=x-pal,r=x+pal-1;
        int len=r-l+1;
        if (r <= n-1-l) {
          //printf("l:%d r:%d\n",l,r);
          seg.modify(l,x-1,len+2*l);
        }
      } else { // Centered at x
        int l=x-pal, r=x+pal;
        int len=r-l+1;
        if (r <= n-1-l) {
          //printf("l:%d r:%d\n",l,r);
          seg.modify(l,x,len+2*l);
        }
      }
    }
  }
  //printf("k:%d\n",k);
  pair<int,pii> best=MP(-INF,MP(-INF,-INF));
  for (int l=0;l<=k;l++) {
    int seq=seg.query(l);
    if (seq != INT_MIN) {
      int plen=max(0,seg.query(l) - 2*l);
      int ans=l*2+plen;
      int r=n-l;
      chkmax(best, MP(ans, MP(l+plen,r)));
    }
  }
  vector<char> final;
  if (best.fst!=-INF) {
    final.reserve(best.fst);
    for (int i=0;i<best.snd.fst;i++) final.PB(s[i]);
    for (int i=best.snd.snd;i<n;i++) final.PB(s[i]);
  }
  return final;
}
void solve() {
  string s; cin>>s;
  vector<char> fwd=go(s);
  reverse(s.begin(),s.end());
  vector<char> bak=go(s);
  reverse(bak.begin(),bak.end());
  if (fwd.size() < bak.size()) {swap(fwd,bak);}
  cout << string(fwd.begin(),fwd.end()) << endl;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t;
  for (int i=0;i<t;i++) solve();
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