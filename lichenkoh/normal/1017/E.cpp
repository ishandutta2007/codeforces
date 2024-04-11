#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
/*
class SuffixArray
{public:
static const int MAXN=2e5+4;
  int * S;
  int N, gap;
  int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

  bool sufCmp(int i, int j)
  {
    if (pos[i] != pos[j])
      return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
  }

  void buildSA(int _N, int * _S)
  {
    S=_S; N=_N;
    REP(i, N) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2)
    {
      sort(sa, sa + N, sufCmp);
      REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
      REP(i, N) pos[sa[i]] = tmp[i];
      if (tmp[N - 1] == N - 1) break;
    }
  }

  void buildLCP()
  {
    for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
    {
      for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
      ++k;
      lcp[pos[i]] = k;
      if (k)--k;
    }
  }
};
*/

typedef pair<int, int> point;
ll len2(point a, point b) {
  ll dx=a.fst-b.fst;
  ll dy=a.snd-b.snd;
  return dx*dx+dy*dy;
}
long long ccw(point a, point b, point c) {
  b.first -= a.first; b.second -= a.second;
  c.first -= a.first; c.second -= a.second;
  return b.first * (long long)c.second - c.first * (long long)b.second;
}

long long dot(point a, point b, point c) {
  return (a.fst-b.fst)*(ll)(c.fst-b.fst) + (a.snd-b.snd)*(ll)(c.snd-b.snd);
}

vector<point> convexHull(vector<point> dat) {
  vector<point> upper, lower;
  sort(dat.begin(), dat.end());
  for(int i = 0; i < dat.size(); i++) {
    while(upper.size() >= 2 && ccw(*++upper.rbegin(),*upper.rbegin(),dat[i]) >= 0) upper.pop_back();
    while(lower.size() >= 2 && ccw(*++lower.rbegin(),*lower.rbegin(),dat[i]) <= 0) lower.pop_back();
    upper.emplace_back(dat[i]);
    lower.emplace_back(dat[i]);
  }
  upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
  return upper;
}
vector<pll> serialize(vector<pii> v) {
  int n=v.size();
  vector<pll> vans;
  for (int i=0;i<n;i++) {
    int k=(i+1); if (k>=n) k-=n;
    int p=(i-1); if (p<0) p+=n;
    ll cw=dot(v[p],v[i],v[k]);
    ll len=len2(v[i],v[k]);
    vans.PB(MP(cw,len));
  }
  return vans;
}

vector<pll> b;
int bins(pll key) {
  int imin=0,imax=b.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (b[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}



class KMP {
// State starts with 0. State is equal to the number of chars in the prefix matched.
// If state = length of string, then it is fully matched.
// Supports further matching after fully matched. Matches may intersect.
// So if pattern = ABAB, and str = ABABAB, then there are 2 matches.
// http://codeforces.com/contest/346/submission/28895320
// http://codeforces.com/contest/346/submission/28895339
public:
  vi fail;
  vi p;
  int gm;
  // Walk the KMP DFA from state j with letter x
  int dfa(int j, int x) {
    //int oldj = j;
    //int z = x - 'A';
    //if (memo[z][j] != -1) {
    //  return memo[z][j];
    //}
    ++j;
    while (j > 0 && x != p[j-1]) {
      j = fail[j];
    }
    //memo[z][oldj] = j;
    return j;
  }
  
  // Build KMP failure table
  void buildfail()
  {
    int m=gm;
    int j = 0;
    for (int i = 1; i <= m; i++) {
      fail[i] = j;
      while (j > 0 && p[i-1] != p[j-1]) {
        j = fail[j];
      }
      j++;
    }
    fail[m+1] = j;
  }
  void init(vi pattern) {
    int m=pattern.size();
    gm=m;
    fail.resize(m+2);
    p=pattern;
    buildfail();
  }
};

KMP kmp;
int n[2];
vector<pll> g[2];
vector<int> q[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int t=0;t<2;t++) n[t]=rint();
  for (int t=0;t<2;t++) {
    vector<pii> v; v.reserve(n[t]);
    for (int i=0;i<n[t];i++) {
      v.PB(MP(rint(),rint()));
    }
    g[t]=serialize(convexHull(v));
  }
  b=g[0];
  for (auto &w:g[1]) b.PB(w);
  sort(b.begin(),b.end());
  auto it=unique(b.begin(),b.end());
  b.resize(it-b.begin());
  for (int t=0;t<2;t++) {
    q[t].reserve(g[t].size());
    for (auto &w:g[t]) {
      //printf("%d ",bins(w));
      //if (n[0]==33&&n[1]==33) printf("%d ",bins(w));
      //printf("w:%lld %lld. b:%d\n",w.fst,w.snd,bins(w));
      q[t].PB(bins(w));
    }
    //printf("\n");
    //if (n[0]==33&&n[1]==33) printf("\n");
  }
  kmp.init(q[0]);
  int x=0;
  for (int k=0;k<2;k++) {
    for (auto &w:q[1]) {
      x=kmp.dfa(x,w);
      //printf("x:%d w:%d\n",x,w);
      if (x==q[0].size()) {
        printf("YES\n"); exit(0);
      }
    }
  }
  printf("NO\n");

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