#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readInt()
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
ld ffabs(ld x) {
  if (x<0) return -x;
  else return x;
}
const ld EPS=1e-13;
ld getf(ld a, ld b, ld imid, bool ismax) {
  ld ans=a*b;
  for (int as=-1;as<=2;as++) for (int bs=-1;bs<=2;bs++) {
    ld na,nb;
    bool ok=1;
    if (as==2) {
      if (ffabs(a)+EPS<=ffabs(imid)) na=0;
      else ok=0;
    }
    else na=a+as*imid;
    if (bs==2) {
      if (ffabs(b)+EPS<=ffabs(imid)) nb=0;
      else ok=0;
    }
    else nb=b+bs*imid;
    if (!ok) continue;
    if (ismax) chkmax(ans,na*nb);
    else chkmin(ans,na*nb);
  }
  return ans;
}
ld solve(ld a, ld b, ld c, ld d) {
  ld lhs=a*b,rhs=c*d;
  if (lhs>rhs) {swap(a,c);swap(b,d);}
  ld imin=0,imax=2e9;
  for (int k=0;k<95;k++) {
    ld imid=(imin+imax)/2;
    ld maxlhs=getf(a,b,imid,true);
    ld minrhs=getf(c,d,imid,false);
    if (maxlhs<minrhs) imin=imid;
    else imax=imid;
  }
  return imin;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b,c,d;cin>>a>>b>>c>>d;
  if (a*d==b*c) {
    printf("0\n");return 0;
  }
  ld final=max(min(abs(a),abs(d)),min(abs(b),abs(c)));
  chkmin(final,solve(a,d,b,c));
  printf("%.12f\n",(double)final);
}