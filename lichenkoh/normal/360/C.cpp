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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
#define DEBUG_CAT
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
const int mn=2001;
char s[2004];
int f[2][mn][mn];
const int MSZ=mn;
typedef int LST;
typedef struct LimitedVecStruct {
  LST a[MSZ];
  int sz;
  void ins(LST val) {
    a[sz++]=val;
  }
} LimitedVec;
LimitedVec v[2][mn];
int id[2][mn][mn];
inline void faddint(int x, int cur, int k, int prev, int val) {
  if (id[cur][k][prev]!=x) {
    id[cur][k][prev]=x;
    v[cur][k].ins(prev);
    f[cur][k][prev]=val;
  }
  else {
    int sum=(f[cur][k][prev]+val);
    if (sum>=MOD) sum-=MOD;
    f[cur][k][prev]=sum;
  }
}
inline void faddll(int x, int cur, int k, int prev, ll val) {
  if (id[cur][k][prev]!=x) {
    id[cur][k][prev]=x;
    v[cur][k].ins(prev);
    f[cur][k][prev]=val%MOD;
  }
  else {
    f[cur][k][prev]=(f[cur][k][prev]+val)%MOD;
  }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,klim; scanf("%d %d\n%s\n",&n,&klim,s);
  int cur=0,nxt=1;
  f[cur][0][0]=1;
  v[cur][0].ins(0);
  for (int x=1;x<=n;x++) {
    for (int k=0;k<=klim;k++) {
      v[nxt][k].sz=0;
    }
    int c=s[n-x]-'a';
    for (int k=0;k<=klim;k++) {
      int sum0=0;
      for (int vi=0;vi<v[cur][k].sz;vi++) {
        int prev=v[cur][k].a[vi],cnt=f[cur][k][prev];
        //printf("x:%d k:%d prev:%d cnt:%d c:%d\n",x,k,prev,cnt,c);
        if (c) {
          sum0=(sum0+cnt*(ll)(c))%MOD;
        }
        if (k+prev<=klim) {
          faddint(x,nxt,k+prev,prev,cnt);
        }
        if (k+x<=klim&&25-c>0) {
          int key=(k+x+x<=klim)?x:klim;
          faddll(x,nxt,k+x,key,cnt*(ll)(25-c));
        }
      }
      if (sum0) {
        faddint(x,nxt,k,0,sum0);
      }
    }
    swap(cur,nxt);
  }
  int ans=0;
  for (int vi=0;vi<v[cur][klim].sz;vi++) {
    int prev=v[cur][klim].a[vi],cnt=f[cur][klim][prev];
    //printf("x:%d k:%d prev:%d cnt:%d\n",n+1,klim,prev,cnt);
    ans+=cnt;
    if (ans>=MOD) ans-=MOD;
  }
  printf("%d\n",ans);
}