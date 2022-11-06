#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

void fail() {
  printf("-1\n"); exit(0);
}

int ur=0,uc=0;
set<pii> good;
set<pii> bad;
int rlim,clim;
vvi ans;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

bool isgood(int r, int c) {
  int gr=0,gc=0;
  for (int nr=r-1;nr<=r+1;nr+=2) {
    if (1<=nr&&nr<=rlim&&ans[nr][c]) gr++;
  }
  for (int nc=c-1;nc<=c+1;nc+=2) {
    if (1<=nc&&nc<=clim&&ans[r][nc]) gc++;
  }
  return gr&&gc;
}

void paint(int r, int c, int val) {
  ans[r][c]=val;
  good.erase(MP(r,c));
  bad.erase(MP(r,c));
  for (int k=0;k<4;k++) {
    int nr=r+dr[k],nc=c+dc[k];
    auto it=bad.find(MP(nr,nc));
    if (it!=bad.end() && isgood(nr,nc)) {
      bad.erase(it);
      good.insert(MP(nr,nc));
    }
  }
}
void ins(int r, int c) {
  if (isgood(r,c)) good.insert(MP(r,c));
  else bad.insert(MP(r,c));
}
void incr() {
  ++ur;
  for (int c=1;c<=uc;c++) ins(ur,c);
}
void incc() {
  ++uc;
  for (int r=1;r<=ur;r++) ins(r,uc);
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>rlim>>clim;
  vvi inp(rlim+1); ans.resize(rlim+1);
  vi rmax(rlim+1),cmax(clim+1);
  for (int r=1;r<=rlim;r++) {
    inp[r].resize(clim+1); ans[r].resize(clim+1);
    for (int c=1;c<=clim;c++) {
      int e; cin>>e;
      inp[r][c]=e;
      chkmax(rmax[r],e);
      chkmax(cmax[c],e);
    }
  }
  vi hi2r(rlim*clim+1),hi2c(rlim*clim+1);
  for (int r=1;r<=rlim;r++) {
    hi2r[rmax[r]]=r;
  }
  for (int c=1;c<=clim;c++) {
    hi2c[cmax[c]]=c;
  }
  for (int val=rlim*clim;val>=1;val--) {
    int ro=hi2r[val],co=hi2c[val];
    if ((!ro)&&(!co)) {
      auto it=good.begin();
      if (it==good.end()) fail();
      int rn=it->fst,cn=it->snd;
      paint(rn,cn,val);
      //printf("val:%d not new put at rn:%d cn:%d\n",val,rn,cn);
    } else {
      if (ro&&co) {
        incr(); incc();
      } else if (ro) {
        incr();
      } else if (co) {
        incc();
      } else {
        assert(0);
      }
      paint(ur,uc,val);
      //printf("val:%d has fresh ro:%d co:%d put at rn:%d cn:%d\n",val,ro,co,ur,uc);
    }
  }
  for (int r=1;r<=rlim;r++) {
    for (int c=1;c<=clim;c++) {
      printf("%d ",ans[r][c]);
    }
    printf("\n");
  }
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