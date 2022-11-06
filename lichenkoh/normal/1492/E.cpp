#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

/*
template<typename T> vector<pair<int, T> > makegroup(vector<T> & a) {
  vector<pair<int,T> > res;
  sort(a.begin(),a.end());
  int n=a.size();
  int cnt=1;
  for (int i=1;i<=n;i++) {
    if (i==n||a[i]!=a[i-1]) {
      res.PB(MP(cnt, a[i-1]));
      cnt=1;
    } else {
      cnt++;
    }
  }
  return res;
}*/
void outp(vi const& b) {
  printf("Yes\n");
  for (auto &w:b) {
    printf("%d ",w);
  }
  printf("\n");
  exit(0);
}
vvi a;
int rlim,clim;
void dfs(vi const &b, int changed) {
  if (changed>=3) return;
  //for (auto &w:b) printf("%d ",w);
  //printf(" changed:%d \n",changed);
  bool needTake=false;
  for (int r=0;r<rlim;r++) {
    vi vdiff;
    for (int c=0;c<clim;c++) {
      if (a[r][c]!=b[c]) vdiff.PB(c);
    }
    int mustTake=int(vdiff.size())-2;
    if (mustTake+changed>2) return;
    if (mustTake>0) {
      needTake=true;
      if (mustTake==1) {
        for (auto &c:vdiff) {
          vi q=b;
          q[c]=a[r][c];
          dfs(q,changed+1);
        }
        return;
      } else if (mustTake==2) {
        int dsz=vdiff.size();
        for (int x=0;x<dsz;x++) for (int y=0;y<x;y++) {
          vi q=b;
          q[vdiff[x]]=a[r][vdiff[x]];
          q[vdiff[y]]=a[r][vdiff[y]];
          dfs(q,changed+2);
        }
        return;
      } else {
        assert(mustTake>=3);
        return;
      }
    }
  }
  if (!needTake) {
    outp(b);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>rlim>>clim;
  a.resize(rlim);
  for (int r=0;r<rlim;r++) {
    a[r].resize(clim);
    for (int c=0;c<clim;c++) {
      cin>>a[r][c];
    }
  }
  dfs(a[0],0);
  printf("No\n");
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