#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
vvi g;
map<pii,int> hd;
map<pii,bool> hs;
vi snake;
int snakelen;

bool getsnake(int x, int p, int dest) {
  if (x==dest) {
    snake.PB(x);
    return true;
  }
  for (auto &y:g[x]) {
    if (y==p) continue;
    bool got=getsnake(y,x,dest);
    if (got) {
      snake.PB(x);
      return true;
    }
  }
  return false;
}

int getd(int x, int p) {
  auto it=hd.find(MP(p,x));
  if (it!=hd.end()) return it->snd;
  int ans=-1;
  for (auto &y:g[x]) {
    if (y==p) continue;
    chkmax(ans,getd(y,x));
    //printf("p:%d x:%d y:%d\n",p,x,y);
  }
  ans++;
  hd[MP(p,x)]=ans;
  //printf("p:%d x:%d d:%d\n",p,x,ans);
  return ans;
}
bool search(int x, int p) {
  auto it=hs.find(MP(p,x));
  if (it!=hs.end()) return it->snd;
  int good=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    int d=getd(y,x);
    if (d>=snakelen-1) good++;
    //printf("x:%d y:%d d:%d snakelen-1:%d good:%d\n",x,y,d,snakelen-1,good);
    bool got=search(y,x);
    if(got) return hs[MP(p,x)]=true;
  }
  return hs[MP(p,x)]=(good>=2);
}
int gethead(int dir) {
  assert(dir==1||dir==-1);
  int head=(dir==-1)?0:snakelen;
  return head;
}
int gettail(int dir) {
  return gethead(-dir);
}
bool go() {
  hd.clear(); hs.clear(); g.clear(); snake.clear(); snakelen=0;
  int n,a,b; cin>>n>>a>>b;
  g.resize(n+1);
  for (int i=1;i<n;i++) {
    int x,y; cin>>x>>y; g[x].PB(y); g[y].PB(x);
    //printf("x:%d y:%d\n",x,y);
  }
  getsnake(a,-1,b);
  snakelen=int(snake.size())-1;
  for (int dir=-1;dir<=1;dir+=2) {
    int head=gethead(dir);
    if (search(snake[head],snake[head-dir])) {
      //printf("dir:%d snake[head]:%d snake[head-dir]:%d\n",dir,snake[head],snake[head-dir]);
      return true;
    }
  }
  int tailmax=0,headmin=snakelen;
  //for (auto &w:snake) printf("%d ",w);
  //printf(" snake\nInit tailmax:%d headmin:%d\n",tailmax,headmin);
  while(1) {
    pii old=MP(tailmax,headmin);
    // Repeated left-right wriggle
    for (int dir=1;dir>=-1;dir-=2) {
      int head=(dir==1)?headmin:tailmax;
      int fwd=getd(snake[head],snake[head-dir]);
      int newtail=head+dir*(min(fwd,snakelen-1)-snakelen);
      if (dir==1) chkmax(tailmax,newtail);
      else chkmin(headmin,newtail);
      //printf("tailmax:%d headmin:%d head:%d fwd:%d newtail:%d\n",tailmax,headmin,head,fwd,newtail);
    }
    if (old==MP(tailmax,headmin)) break;
  }
  {
    int head=gethead(1);
    int tail=gettail(1);
    for (int h=headmin;h<head;h++) {
      if (search(snake[h],snake[h-1])) return true;
    }
    for (int t=tail+1;t<=tailmax;t++) {
      if (search(snake[t],snake[t+1])) return true;
    }
  }
  return false;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t;
  for (int i=0;i<t;i++) {
    bool got=go();
    printf(got?"YES\n":"NO\n");
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