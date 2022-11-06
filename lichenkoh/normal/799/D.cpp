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
const int mn=1e5+4;
int v[mn];
bitset<mn> f[2];
int solve(int a, int b, int n) {
  if (a<=1&&b<=1) return 0;
  f[0].reset();
  f[0][1]=true;
  int cur=0,nxt=1;
  ll prod=1;
  for (int p=0;p<n;p++) {
    f[nxt].reset();
    int val=v[p];
    ll res=val;
    ll bx=b;
    for (int x=1;x<a;x++) {
      if (f[cur][x]) {
        if (prod>=bx && res>=a) {
          return p+1;
        }
        f[nxt][x]=true;
        if (res<a) f[nxt][res]=true;
      }
      res+=val;
      bx+=b;
    }
    prod*=(ll)val;
    swap(cur,nxt);
  }
  return 1e9+5;
}
int solve2(int a, int b, int n) {
  return min(solve(a,b,n),solve(b,a,n));
}
int ceil(int x, int y) {
  return (x+y-1)/y;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int a=readInt(),b=readInt(),h=readInt(),w=readInt(),n=readInt();
  for (int i=0;i<n;i++) v[i]=readInt();
  sort(v,v+n,greater<int>());
  int ans=min(
    solve2(ceil(a,h),ceil(b,w),n),
    solve2(ceil(a,w),ceil(b,h),n)
    );
  if (ans>=1e9-5) ans=-1;
  printf("%d\n",ans);
}