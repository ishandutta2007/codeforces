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
const int mn=1e5+4;
vector<pll> v[2];
ll vs[mn],va[mn],vb[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint(),sperp=rint();
  ll alls=0;
  ll base=0;
  for (int i=0;i<n;i++) {
    vs[i]=rint(),va[i]=rint(),vb[i]=rint();
    if (va[i]>vb[i]) {
      v[0].PB(MP(va[i]-vb[i],vs[i]));
    }
    else if (vb[i]>va[i]){
      v[1].PB(MP(vb[i]-va[i],vs[i]));
    }
    base+=min(va[i],vb[i])*(ll)vs[i];
    alls+=vs[i];
  }
  for (int t=0;t<2;t++) {
    sort(v[t].begin(), v[t].end());
    reverse(v[t].begin(), v[t].end());
  }
  ll wanta=0;
  for (auto &w:v[0]) {
    wanta+=w.snd;
  }
  ll totp=(alls+sperp-1)/sperp;
  ll wantap=wanta/sperp;
  ll final=0;
  for (ll canda=max(0ll,wantap-2);canda<=min(totp,wantap+2);canda++) {
    ll candb=totp-canda;
    if (0<=candb&&candb<=totp) {
      ll pa=canda*sperp,pb=candb*sperp;
      ll gain=0;
      for (auto &w:v[0]) {
        ll take=min(pa,w.snd);
        gain+=take*(ll)w.fst;
        pa-=take;
      }
      for (auto &w:v[1]) {
        ll take=min(pb,w.snd);
        gain+=take*(ll)w.fst;
        pb-=take;
      }
      //printf("%lld %lld %lld\n",canda,candb,gain);
      chkmax(final,gain);
    }
  }
  //printf("base:%lld\n",base);
  final+=base;
  printf("%lld\n",final);

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