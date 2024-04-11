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
mt19937 rng;
// uniform_int_distribution<int>(0, i)(rng)
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
template<typename T> void makeunique(vector<T> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
ll rempow2(ll x) {
  int k=__builtin_ffsll(x);
  if (k>=2) x=x>>(k-1);
  return x;
}
const int mn=(2e5)+4;
ll a[mn];
int main() 
{
  auto start = std::chrono::high_resolution_clock::now();
  rng.seed(start.time_since_epoch().count());
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rlong();
  int final=0;
  for (int i=0;i<n;i++) final+=(a[i]&1);
  set<ll> st,sg;
  while(1) {
    if (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() > 2000) {
      printf("%d\n",final);
      exit(0);
    }
    int rd_int=-1;
    for (int k=0;k<40;k++) {
      rd_int = uniform_int_distribution<int>(1, n-1)(rng);
      if (st.find(a[rd_int]) == st.end()) break;
    }
    if (rd_int==-1) continue;
    st.insert(a[rd_int]);
    swap(a[0],a[rd_int]);
    vector<ll> v;
    for (ll s=max(a[0]-1,2LL); s<=a[0]+1; s++) {
      for (int i=1;i<n;i++) {
        for (ll t=max(a[i]-1,2LL); t<=a[i]+1;t++) {
          ll g=__gcd(s,t);
          ll gno2=rempow2(g);
          if (gno2>1 && sg.find(gno2)==sg.end()) {
            v.PB(gno2);
            sg.insert(gno2);
          }
        }
      }
    }
    makeunique(v);
    for (auto og:v) {
      if (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() > 2000) {
        printf("%d\n",final);
        exit(0);
      }
      ll g=og;
      int ans=0;
      for (int i=0;i<n;i++) {
        ll rem=a[i]%g;
        ll absrem=g-rem;
        if (a[i]-rem>=1) chkmin(absrem,rem);
        if (absrem <= 1) {
          ans+=absrem;
          //if (og==3) printf("ans:%d a[i]:%d absrem:%d\n",ans,a[i],absrem);
        } else {
          int maxk=final-ans;
          bool ok=false;
          for (int k=2;k<=maxk;k++) {
            for (int sgn=-1;sgn<=1;sgn+=2) {
              ll nx=a[i]+k*sgn;
              if (nx>=2) {
                ll g2=__gcd(g,nx);
                if (g2>1) {
                  ok=true;
                  g=g2;
                  ans+=k;
                  //if (og==3) printf("og:%d g2:%lld a[i]:%d k:%d ans:%d\n",og,g2,a[i],k,ans);
                  break;
                }
              }
            }
            if (ok) break;
          }
          if (!ok) {
            //if (og==3) printf("og:%d not ok\n");
            ans=final+1;
          }
        }
        if (ans>=final) break;
      }
      /*if (ans==3) {
        for (int i=0;i<n;i++) printf("%lld ",a[i]);
        printf("OK og:%d\n",og);
      }*/
      if (ans < final) final=ans;
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