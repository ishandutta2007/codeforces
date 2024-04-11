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
bitset<2> d;
int n; ll l; ll x[2];
set<ll> s;
set<ll> solve(int t) {
  set<ll> ans;
  for (auto &w:s) {
    if (w>=x[t])   {ans.insert(w-x[t]); return ans;}
    if (l-w>=x[t]) {ans.insert(w+x[t]); return ans;}
  }
  ans.insert(0); ans.insert(x[t]); return ans;
}
bool valid(ll x) {
  return 0<=x&&x<=l;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  n=readInt();l=readInt(),x[0]=readInt(),x[1]=readInt();
	for (int i=0;i<n;i++) {
    int a=readInt();
    s.insert(a);
  }
  d.reset();
  for (auto &w:s) {
    for (int t=0;t<2;t++) {
      if (s.find(w-x[t])!=s.end()||s.find(w+x[t])!=s.end()) d[t]=1;
    }
  }
  if (d.count()==2) {
    printf("0\n");
    return 0;
  }
  if (d.count()==1) {
    int tneed=-1;
    for (int t=0;t<2;t++) if (!d[t]) tneed=t;
    auto got=solve(tneed);
    printf("%lld\n",(ll)got.size());
    for (auto &w:got) printf("%lld ",w);
    printf("\n");
    return 0;
  }
  for (auto &w:s) {
    if (w+x[1]<=l) {
      if (s.find(w+x[1]-x[0])!=s.end()||s.find(w+x[1]+x[0])!=s.end()) {
        printf("1\n%lld\n",w+x[1]);
        return 0;
      }
    }
    if (w-x[1]>=0) {
      if (s.find(w-x[1]+x[0])!=s.end()||s.find(w-x[1]-x[0])!=s.end()) {
        printf("1\n%lld\n",w-x[1]);
        return 0;
      }
    }
  }
  for (auto &w:s) {
    for (int as=-1;as<=1;as+=2) for (int bs=-1;bs<=1;bs+=2) for (int k=0;k<2;k++) {
      if (valid(w+as*x[0])&&valid(w+as*x[0]+bs*x[1])) {
        printf("2\n%lld %lld\n",w+as*x[0],w+as*x[0]+bs*x[1]);
        return 0;
      }
      swap(x[0],x[1]);
    }
  }
  set<ll> res;
  for (int t=0;t<2;t++) if (!d[t]) {
    auto got=solve(t);
    for (auto &w:got) res.insert(w);
  }
  printf("%lld\n",(ll)res.size());
  for (auto &w:res) {
    printf("%lld ",w);
  }
  printf("\n");
  return 0;
}