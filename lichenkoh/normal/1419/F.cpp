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
using vpii=vector<pii>;
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
  // Ok, special pt can only connect <=4 components.
  // Q_x = {(x_1 + x_2) / 2 | (x_1,y_c) (x_2,y_c) adjacent in P without other p in between, forall y_c}
  // x \in X union Q_x
  // y \in Y union Q_y

template<typename T> void makeunique(vector<T> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<pii> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid].fst<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

const int mn=1002;

const int mx=mn;
class UnionFind {
  typedef int UFTYPE;
public:
  UFTYPE ufIdentity = -1;
  int ufParent[mx];
  int rank[mx];
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufParent[x]=x;
      rank[x]=0;
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
  }
};

const int me=(mn*(mn-1))/2;
int P[mn][2];
vector<pair<int,pii> > E;
vi Q[2];
map<int,vpii> h[2];
int n;
const int CX=0,CY=1;


UnionFind uf;
char res[mn*2][mn*2];
bool f(int imid) { // O(n^2)
  // Get connected components
  uf.init(n);
  for (auto &e:E) {
    if (e.fst > imid) break;
    uf.funion(e.snd.fst,e.snd.snd);
  }
  int comps=0;
  map<int,int> comph;
  for (int id=0;id<n;id++) {
    if (uf.ffind(id)==id) {
      comps++;
      if (comps > 4) return false;
      comph[id]=comps-1;
    }
  }
  memset(res,0,sizeof res);
  for (int c=0;c<2;c++) {
    for (int xi=0;xi<Q[c].size();xi++) {
      int x=Q[c][xi];
      auto it=h[c].find(x);
      if (it==h[c].end()) continue;
      int k=0;
      for (int yi=0;yi<Q[c^1].size();yi++) {
        int y=Q[c^1][yi];
        while(k < it->snd.size() && it->snd[k].fst < y) ++k;
        int rlim=min((int)it->snd.size(), k+1);
        int sig=0;
        for (int r=max(0,k-1);r < rlim;r++) {
          if (abs(y- it->snd[r].fst) <= imid){
            int id=uf.ffind(it->snd[r].snd);
            //printf("c:%d x:%d y:%d it->snd[r].snd:%d id:%d comph[id]:%d\n",c,x,y,it->snd[r].snd,id,comph[id]);
            sig |= 1<<comph[id];
          }
        }
        if (c==0) {
          if (sig==(1<<comps)-1) return true;
          res[xi][yi]=sig;
        } else {
          if ((res[yi][xi]|sig) == (1<<comps)-1) return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int id=0;id<n;id++) {
    int x=rint(),y=rint();
    P[id][0]=x; P[id][1]=y;
    h[CX][x].PB(MP(y,id));
    h[CY][y].PB(MP(x,id));
  }
  for (int c=0;c<2;c++) {
    for (auto &w:h[c]) {
      Q[c].PB(w.fst);
      sort(w.snd.begin(),w.snd.end());
      for (int i=1;i<w.snd.size();i++) {
        int t0=w.snd[i-1].fst,t1=w.snd[i].fst;
        int id0=w.snd[i-1].snd,id1=w.snd[i].snd;
        Q[c^1].PB((t0+t1)/2);
        int d=t1-t0;
        E.PB(MP(d,MP(id0,id1)));
      }
    }
  }
  sort(E.begin(),E.end());
  for (int c=0;c<2;c++) makeunique(Q[c]);
  //printf("f(3):%d\n",f(3)?1:0); return 0;

  int imin=0,imax=2000000004;
  while(imin<imax) {
    int imid=imin+(imax-imin)/2;
    if (!f(imid)) imin=imid+1;
    else imax=imid;
  }
  if (imin==2000000004) imin=-1;
  printf("%d\n",imin);
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