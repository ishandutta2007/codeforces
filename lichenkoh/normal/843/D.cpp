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
const ll INF=1e18;
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
typedef pair<ll,int> pli;
typedef vector<pli> vpli;
const int mn=100002;
vector<int> g[mn];
int vs[mn],vt[mn],vc[mn];
int n;
ll vh[mn];
void dij(int init) {
  priority_queue<pli,vpli,greater<pli> > pq;
  vh[init]=0;
  for (int x=2;x<=n;x++) vh[x]=INF;
  pq.push(MP(0ll,init));
  while(!pq.empty()) {
    pli top=pq.top(); pq.pop();
    int x=top.snd; ll distx=top.fst;
    if (distx>vh[x]) continue;
    for (auto &ei:g[x]) {
      ll ndist=distx+vc[ei];
      int y=vt[ei];
      if (ndist<vh[y]) {
        vh[y]=ndist;
        pq.push(MP(ndist,y));
      }
    }
  }
}

const int mq=1000000+2;
//vector<int> vv[mq];
int vdist[mn];

/*class FastQueue {
public:
  int a[mn];
  int l=0,r=0;
  void rst() {
    l=0;r=0;
  }
  void push(int x) {
    a[r++]=x;
  }
  int pop() {
    return a[l++];
  }
  int sz() {
    return r-l;
  }
};
FastQueue vq;*/
bitset<mq> qd;

typedef struct Node {
public:
  int val;
  struct Node *next;
} Node;

class GroupVec {
public:
  Node prealloc[mn];
  Node *group[mq];
  int used=0;
  void rst() {
    used=0;
    memset(group,0,sizeof group);
  }
  void push(int id, int val) {
    Node *newnode=&(prealloc[used++]);
    newnode->val=val;
    newnode->next=group[id];
    group[id]=newnode;
  }
};

GroupVec vv;

//int numproc=0;
//int numx=0;
inline void proc(int x, int d) {
  //numx++;
  int distx=vdist[x];
  if (d>distx) return;
  for (auto &ei:g[x]) {
    //numproc++;
    int ndist=distx+vc[ei];
    int y=vt[ei];
    //if (qi==4)printf("x:%d (%lld) y:%d (%lld)\n",x,distx,y,ndist);
    if (ndist<vdist[y]) {
      vdist[y]=ndist;
      vv.push(ndist,y);
      //vv[ndist].PB(y);
      qd[ndist]=true;
    }
  }
}
void getans(int init) {
  vdist[init]=0;
  //vv[0].PB(init);
  vv.rst();
  vv.push(0,init);
  fill(vdist+2, vdist+n+1, mq);
  //qd[0]=true;
  qd.reset();
  for(int d=0;d< mq;d = qd._Find_next(d)) {
  //for (int d=0;d<mq;d++) {
    if (d>0&&!qd[d]) continue;
    Node *node=vv.group[d];
    while(node!=NULL) {
      int x=node->val;
      vv.group[d]=node->next;
      proc(x,d);
      node=vv.group[d];
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int m=rint(),q=rint();
  for (int ei=1;ei<=m;ei++) {
    int x=rint(); vs[ei]=x; vt[ei]=rint(); vc[ei]=rint();
    g[x].PB(ei);
  }
  dij(1);
  //for (int x=1;x<=n;x++) printf("x:%d vh:%lld\n",x,vh[x]);
  for (int ei=1;ei<=m;ei++) {
    int s=vs[ei],t=vt[ei];
    ll res=vc[ei]+vh[s]-vh[t];
    vc[ei]=(res>mq)?mq:res;
    //printf("ei:%d vw:%lld\n",ei,vw[ei]);
  }
  int ksum=0;
  bool ch=0;
  for (int qi=0;qi<q;qi++) {
    //printf("qi:%d\n",qi);
    int t=rint();
    if (t==1) {
      if (ch) {
        getans(1);
        ch=0;
      }
      int x=rint();
      ll ans=vdist[x]-vh[1]+vh[x];
      if (ans>=INF/2) ans=-1;
      printf("%lld\n",ans);
    }
    else {
      int k=rint();
      ksum+=k;
      for (int i=0;i<k;i++) {
        int ei=rint();
        vc[ei]++;
      }
      ch=1;
    }
  }
  //printf("numproc:%d numx:%d\n",numproc,numx);
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