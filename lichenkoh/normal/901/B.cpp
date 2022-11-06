#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
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
void pr(const vi &p) {
  for (auto &w:p) printf("%d ",w); printf("\n");
}
// returns a, b such that ax = by in the field we're talking about
inline void solve(int x, int y, int& a, int& b) {a=y; b=x;}
inline vi remove_leading_zero(vi v) {
  vi vans;
  bool ok=0;
  for (auto &w:v) {
    if (ok||(w!=0)) {
      ok=1; vans.PB(w);
    }
  }
  return vans;
} // 00002342 -> 2343; 0 -> 0
// polynomial coefficients are in decreasing order of exponents
inline vi operator% (const vi& p, const vi& q) {
  vi copy(p.begin(), p.end()); int diff = p.size()-q.size(), a, b;
  for (int i = 0; i <= diff; ++i) {
    solve(q[0], copy[i], a, b);
    for (auto j = 0u; j < p.size(); ++j) copy[j] *= b;
    for (auto j = 0u; j < q.size(); ++j) copy[i+j] -= a*q[j];
  }
  return remove_leading_zero(copy); }
int gstep;

vi gcd(const vi &p, const vi &q){
  //pr(p); pr(q); printf("gstep:%d\n",gstep); fflush(stdout);
  gstep++;
  return (q.size()==0||(q.size()==1 && !q[0])) ? p : gcd(q,p%q);
}

inline vi operator* (const vi &p, const int &c) {
  vi vans=p;
  for (int i=0;i<p.size();i++) vans[i]*=c;
  return vans;
}
inline vi operator+ (const vi &p, const vi &q) {
  size_t sz=max(p.size(),q.size());
  vi vans(sz);
  for (int i=0;i<p.size();i++) vans[i]=p[i];
  for (int i=0;i<q.size();i++) vans[i]+=q[i];
  return vans;
}
bool isok(const vi &p) {
  for (auto &w:p) {
    if (abs(w)>1) return false;
  }
  return true;
}

int check(vi a, vi b) {
  reverse(a.begin(),a.end());reverse(b.begin(),b.end());
  gstep=-1;
  gcd(a,b);
  //printf("gstep:%d\n",gstep);
  return gstep;
}
pair<vi,vi> f(vi a, vi b, int r) {
  //pr(a); pr(b); printf("end r:%d\n\n",r);
  if (r==0) return MP(a,b);
  vi ax; ax.PB(0); for (auto &w:a) ax.PB(w);
  vi c=ax+b;
  //pr(ax); printf("end ax\n"); pr(c); printf("end c\n");
  if (!isok(c)) {
    vi nax=ax*(-1);
    c=nax+b;
  }
  assert(isok(c));
  return f(c,a,r-1);
}

pair<vi,vi> solve(int want) {
  vi sa={0,1};
  vi sb={-1};
  auto got=f(sa,sb,want-1);
  vi a=got.fst,b=got.snd;
  assert(a.size()==want+1);
  assert(b.size()==want);
  if (b[b.size()-1]==-1) {
    for (auto &w:b) w*=-1;
  }
  if (a[a.size()-1]==-1) {
    for (auto &w:a) w*=-1;
  }
  assert(a[a.size()-1]==1);
  assert(b[b.size()-1]==1);
  int test=check(a,b);
  assert(test==want);
  return MP(a,b);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int want; scanf("%d",&want);
  auto got=solve(want);
  printf("%d\n",want); pr(got.fst);
  printf("%d\n",want-1); pr(got.snd);
  //for (int want=1;want<=150;want++) {
  //  solve(want);
  //}
  //while(1) {
  //  go();
  //}
  //vi a={1,-2,0,-4};
  //vi b={1,-3};
  //vi c=a%b;
  //pr(c);
  
  //vi a={1,0,-1};
  //vi b={1,0};
  //auto got=gcd(a,b);
  //printf("gstep:%d\n",gstep);
  //for (auto &w:got) printf("%d ",w);
  //printf("\n");
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