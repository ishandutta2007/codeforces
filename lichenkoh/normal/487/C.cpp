#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
bitset<100> s;
int a[100];
bool solve(int n) {
  for (int x=0;x<n;x++) a[x]=x+1;
  do {
    s.reset();
    int prod=a[0];
    s[prod]=1;
    for (int x=1;x<n;x++) {
      prod=(prod*a[x])%n;
      s[prod]=1;
    }
    if (s.count()==n) {
      for (int x=0;x<n;x++) printf("%d ",a[x]);
      printf("\n");
      return true;
    }
  } while(next_permutation(a,a+n));
  return false;
}
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int n=1;n<=14;n++) {
  //  printf("n:%d res:%d\n",n,solve(n));
  //}
  
  int n; scanf("%d",&n);
  if (n==1) {
    printf("YES\n1\n");
    return 0;
  }
  if (n==4) {
    printf("YES\n1\n3\n2\n4\n");
    return 0;
  }
  int slim=min(n-1,(int)ceil(sqrt(n))+1);
  for (int x=2;x<=slim;x++) {
    if (n%x==0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  printf("1\n");
  for (int x=2;x<n;x++) {
    int ans=(x*mod_pow(x-1,n-2,n))%n;
    printf("%d\n",ans);
  }
  printf("%d\n",n);
}