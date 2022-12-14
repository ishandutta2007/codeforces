#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __float128 dd;
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
const int mn=52;
int a[mn];
ld f[2][mn][mn];
ld g[mn];
dd vlog[mn];
dd vlogfact[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int x=1;x<=n;x++) vlog[x]=log((ld)x);
  {
    dd sum=0;
    vlogfact[0]=0;
    for (int x=1;x<=n;x++) {
      sum+=vlog[x];
      vlogfact[x]=sum;
    }
    //for (int x=1;x<=n;x++) vlogfact[x]-=sum;
  }
  for (int i=0;i<n;i++) a[i]=rint();
  sort(a,a+n,greater<int>());
  int p=rint();
  int cur=0,nxt=1;
  f[0][0][0]=1;
  for (int i=0;i<n;i++) {
    memcpy(f[nxt],f[cur],sizeof f[cur]);
    int v=a[i];
    for (int k=0;k<n;k++) {
      for (int x=0;x<=p;x++) {
        ld have=f[cur][k][x];
        int nx=x+v,nk=k+1;
        if (nx<=p) f[nxt][nk][nx]+=have;
      }
    }
    swap(cur,nxt);
  }
  dd final=0;
  for (int k=1;k<=n;k++) {
    dd sum=0;
    for (int x=0;x<=p;x++) sum+=f[cur][k][x];
    dd tomul=exp((ld)(vlogfact[n-k]+vlogfact[k]-vlogfact[n]));
    //printf("k:%d sum:%f fact:%f\n",k,(double)sum,(double)tomul);
    final+=tomul*sum;
  }
  cout<<fixed<<setprecision(20);
  cout<<(long double)final<<endl;
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