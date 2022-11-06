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
const ll INF=1LL<<47;
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

void go() {
  int n,m; cin>>n>>m;
  vll vp(n); for (int i=0;i<n;i++) cin>>vp[i];
  vpll vseg(m); for (int i=0;i<m;i++) cin>>vseg[i].fst>>vseg[i].snd;
  vp.PB(-INF); vp.PB(INF);
  sort(vp.begin(),vp.end());
  sort(vseg.begin(),vseg.end());
  n=vp.size();
  vector<vpll> aseg(n+1);
  {
    int k=0;
    for (auto &seg:vseg) {
      while(k+1 < n && (vp[k+1]<seg.fst)) {
        ++k;
      }
      if (k+1<n) {
        if (vp[k] < seg.fst && seg.snd < vp[k+1]) {
          aseg[k].PB(seg);
        }
      }
    }
  }

  for (auto &w:aseg) sort(w.begin(),w.end());
  ll oldfwd=0,oldback=0;
  for (ll k=0;k<n-1;k++) {
    ll fwd=INF,back=INF;
    if (aseg[k].size()==0) {
      back=fwd=min(oldfwd,oldback);
    } else {
      ll t=aseg[k].size();
      sort(aseg[k].begin(),aseg[k].end(),greater<pll>());
      ll leastr=INF;
      // s=0: Left takes all
      for (int s=0;s<t;s++) {
        auto seg=aseg[k][s];
        assert(seg.fst>vp[k]);
        assert(seg.snd < vp[k+1]);
        ll leftgo=min(
          oldfwd + (seg.fst - vp[k]),
          oldback + 2*(seg.fst-vp[k])
          );
        ll rightgo=max(0LL, vp[k+1] - leastr);
        chkmin(fwd,  leftgo + 2*rightgo);
        chkmin(back, leftgo + rightgo);
        chkmin(leastr,seg.snd);
      }
      // Right takes all
      {
        chkmin(fwd, oldback + 2*(vp[k+1] - leastr));
        chkmin(back, oldback + (vp[k+1] - leastr));
      }
    }
    oldfwd=fwd;
    oldback=back;
  }
  printf("%lld\n",min(oldfwd,oldback));
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