#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
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

int MOD;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MP make_pair
vvi matrixUnit(int n) {
  vvi res(n, vi(n));
  for (int i = 0; i < n; i++) res[i][i] = 1;
  return res;
}

vvi matrixMul(const vvi &a, const vvi &b) {
  int n = a.size();
  int m = a[0].size();
  int k = b[0].size();
  vvi res(n, vi(k));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
      for (int p = 0; p < m; p++)
        res[i][j] = (res[i][j] + (long long) a[i][p] * b[p][j]) % MOD;
  return res;
}

void matrixMult(vvi &res, const vvi &a, const vvi &b) {
  int n = a.size();
  int m = a[0].size();
  int k = b[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++)
    {
      int ans=0;
      for (int p = 0; p < m; p++)
        ans = (ans + (long long) a[i][p] * b[p][j]) % MOD;
      res[i][j]=ans;
    }
  }
}

vvi matrixPow(const vvi &a, ll p) {
  vvi base=a;
  int n=base.size();
  vvi ans=matrixUnit(n);
  vvi tmp(n, vi(n));
  while(p>0) {
    if (p&1) {
      matrixMult(tmp,ans,base);
      ans=tmp;
    }
    matrixMult(tmp,base,base);
    base=tmp;
    p>>=1;
  }
  return ans;
}

int getfib(ll n) {
  vvi mat(2,vi(2));
  mat[0][0]=mat[0][1]=mat[1][0]=1;
  mat[1][1]=0;
  vvi res=matrixPow(mat, n);
  int ans=res[1][0];
  return ans;
}
const int MAXC=1000000+4;
ll getg(ll l, ll r, ll k) {
  if (k==1) return r;
  k--;
  ll ans=1;
  for (ll a=1;a<MAXC;a++) {
    ll g=r/(a+k);
    if (l<=a*g) chkmax(ans,g);
  }
  for (ll g=MAXC-1;g>=2;g--) {
    ll a=(l+g-1)/g;
    if ((a+k)*g<=r) chkmax(ans,g);
  }
  //printf("g:%lld\n",ans);
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  MOD=rint(); ll l=rlong(),r=rlong(),k=rlong();
  ll g=getg(l,r,k);
  int ans=getfib(g);
  printf("%d\n",ans);
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