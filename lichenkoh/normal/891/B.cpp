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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

vector<int> bf(vi a) {
  vi v=a;
  sort(v.begin(),v.end());
  int n=v.size();
  int zlim=(1<<(v.size()))-1;
  do {
    bool ok=1;
    for (int z=1;z<zlim;z++) {
      int x=0,y=0;
      for (int i=0;i<n;i++) {
        if((1<<i)&z) {
          x+=a[i];y+=v[i];
        }
      }
      if (x==y) {ok=0; break;}
    }
    if (ok) return v;
  } while(next_permutation(v.begin(),v.end()));
  return {-1};
}


vector<int> gen() {
  int n=1+(rand()%6);
  set<int> s;
  for (int i=0;i<n;i++) {
    s.insert(rand()%16);
  }
  vector<int> v;
  for (auto &w:s) v.PB(w);
  sort(v.begin(),v.end());
  return v;
}

bool check(vi a, vi v) {
  int n=v.size();
  int zlim=(1<<(v.size()))-1;
    bool ok=1;
    for (int z=1;z<zlim;z++) {
      int x=0,y=0;
      for (int i=0;i<n;i++) {
        if((1<<i)&z) {
          x+=a[i];y+=v[i];
        }
      }
      if (x==y) {ok=0; break;}
    }
    return ok;
}

vector<int> solve(vector<int> a) {
  vector<pii> v;
  int n=a.size();
  for (int i=0;i<n;i++) v.PB(MP(a[i],i));
  sort(v.begin(),v.end());
  int orig=v[0].fst;
  for (int i=1;i<n;i++) v[i-1].fst=v[i].fst;
  v[n-1].fst=orig;
  vi ans(n);
  for (auto &w:v) {
    int i=w.snd;
    int x=w.fst;
    ans[i]=x;
  }
  if (!check(a,ans)) {
    for (auto &w:a) printf("%d ",w);
  }
  return ans;
}

void go() {
  for (int k=0;k<100000;k++) {
    vector<int> v=gen();
    random_shuffle(v.begin(),v.end());
    solve(v);
    /*vi bfed=bf(v);
    vi ans=solve(v);
    if (bfed!=ans) {
      for (auto &w:v) printf("%d ",w);
      printf(" inp\n");
      for (auto &w:ans) printf("%d ",w);
      printf(" ans\n");
    }*/
  }
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go(); return 0;
  int n=rint();
  vector<int> a; for (int i=0;i<n;i++) a.PB(rint());
  auto ans=solve(a);
  for (auto &w:ans) printf("%d ",w);
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