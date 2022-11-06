#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
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
vi a,vfinal;
void act(int x) {
  //printf("Act on: %d %d %d\n",x,x+1,x+2);
  vfinal.PB(x);
  int store=a[x]^a[x+1]^a[x+2];
  a[x]=a[x+1]=a[x+2]=store;
}
void go() {
  vfinal.clear();
  int n; cin>>n;
  a.resize(n);
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  vpii vp;
  int last=-1;
  for (int i=0;i<n;i++) {
    if (a[i]==1) {
      if (last==-1) {
        last=i;
      } else {
        vp.PB(MP(last,i));
        last=-1;
      }
    } else {
      if (last==-1) {
        vp.PB(MP(i,-1));
      }
    }
  }
  
  if (last!=-1) {
    printf("NO\n"); return;
  }
  queue<int> q;
  vector<bool> vdone(vp.size());
  for (int pi=0;pi<vp.size();pi++) {
    int l=vp[pi].fst,r=vp[pi].snd;
    if (r==-1) {
      vdone[pi]=true;
      q.push(pi-1); q.push(pi+1);
    } else {
      int z=r-l-1;
      if (z%2==1) {
        for (int x=l;x+2<r;x+=2) {
          act(x);
        }
        for (int x=r-2;x>=l;x-=2) {
          act(x);
        }
        vdone[pi]=true;
        q.push(pi-1); q.push(pi+1);
      }
    }
  }
  while(!q.empty()) {
    int pi=q.front(); q.pop();
    if (0<=pi&&pi<vp.size()&&!vdone[pi]) {
      int l=vp[pi].fst,r=vp[pi].snd;
      if (pi-1>=0&&vdone[pi-1]) {
        for (int x=r-2;x>=l;x-=2) {
          act(x);
        }
        for (int x=l-1;x+2<=r;x+=2) {
          act(x);
        }
      } else {
        assert(vdone[pi+1]);
        for (int x=l;x+2<r;x+=2) {
          act(x);
        }
        for (int x=r-1;x>=l;x-=2) {
          act(x);
        }
      }
      vdone[pi]=true;
      q.push(pi-1); q.push(pi+1);
    }
  }
  for (auto done:vdone) {
    if (!done) {
      printf("NO\n"); return;
    }
  }
  printf("YES\n%d\n",int(vfinal.size()));
  for (auto &x:vfinal) {
    printf("%d ",x+1);
  }
  printf("\n");
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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