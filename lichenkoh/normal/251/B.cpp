#include <bits/stdc++.h>
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
const int mn=104;
int q[mn];
int f[mn];
int s[mn];
int tmp[mn];
int n;
void apply(int *targ, int *perm) {
  for (int i=0;i<n;i++) {
    tmp[perm[i]]=targ[i];
  }
  for (int i=0;i<n;i++) targ[i]=tmp[i];
}
void applyrev(int *targ, int *perm) {
  for (int i=0;i<n;i++) {
    tmp[i]=targ[perm[i]];
  }
  for (int i=0;i<n;i++) targ[i]=tmp[i];
}
bool eq(int *a, int *b) {
  for (int i=0;i<n;i++) if (a[i]!=b[i]) return false;
  return true;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int k=rint();
  for (int i=0;i<n;i++) {
    q[i]=rint()-1;
  }
  for (int i=0;i<n;i++) {
    s[i]=rint()-1;
  }
  int need1=1e9;
  for (int i=0;i<n;i++) f[i]=i;
  for (int t=0;t<=k;t++) {
    if (eq(f,s)) {
      chkmin(need1,t); break;
    }
    apply(f,q);
  }
  int need2=1e9;
  for (int i=0;i<n;i++) f[i]=i;
  for (int t=0;t<=k;t++) {
    if (eq(f,s)) {
      chkmin(need2,t); break;
    }
    applyrev(f,q);
  }
  int need=min(need1,need2);
  bool ok=(need1<=k&&0==(k-need1)%2)||(need2<=k&&0==(k-need2)%2);
  if (need==0&&k>0) ok=false;
  if (need1==1&&need2==1&&k>=2) ok=false;
  if (ok) printf("YES\n");
  else printf("NO\n");
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