#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

template<typename T, int _MAXLOG> class BasisRaw {
public:
    static const int MAXLOG = _MAXLOG;
    T base[MAXLOG];

    BasisRaw()
    {
      memset(base,0,sizeof base);
    }

    void add(T val)
    {
      for(int i = MAXLOG - 1; i >= 0; i--) {
        if((val >> i) & 1)
        {
          if(!base[i]) { base[i] = val; return; }
          else val ^= base[i];
        }
      }
    }

    T min_xor(T seed)
    {
      T res = seed;
      for(int i = MAXLOG-1; i >= 0; i--) {
        if(((res >> i) & 1) && base[i]) {res ^= base[i];}
      }
      return res;
    }
};

typedef BasisRaw<int32_t, 30> Basis;

template<typename T, int arraySize, int rollbackSize> class RollbackArray {
  public:
  T arr[arraySize];
  pair<int,T> rollbackArr[rollbackSize]; // Describes the last operation BEFORE time ts.
  int ts=0;
  void rst() {ts=0;}
  void fill(int start, int end, int val) {
    std::fill(arr+start, arr+end+1, val);
  }
  T operator [](int i) const {return arr[i];}
  void modify(int i, T val) {
    ++ts;
    rollbackArr[ts]=MP(i,arr[i]);
    arr[i]=val;
  }
  //T & operator [](int i) { // kind of risky
  //  ++ts; rollbackArr[ts]=MP(i,arr[i]);
  //  return arr[i];
  //}
  void rollback(int new_ts) {
    while(ts>new_ts) {
      auto &w=rollbackArr[ts];
      arr[w.fst]=w.snd;
      --ts;
    }
  }
};


template<int size> class MergeRankRollback {
public:
  typedef struct _S {
    int parent;
    int val;
    int rank;
  } S;
  RollbackArray<S,size,40*size> data;
  MergeRankRollback() {
    for (int x=0;x<size;x++) data.arr[x]={x,0,0};
  }
  pii getRootAndVal(int x) {
  	//printf("x:%d par:%d\n",x,data[x].parent);
    if (data[x].parent==x) {
      return MP(x,0);
    }
    else {
      pii got=getRootAndVal(data[x].parent);
      return MP(got.fst,got.snd^data[x].val);
    }
  }
  void addEdge(int x, int y, int d, Basis &basis) {
  	//printf("add: %d %d %d\n",x,y,d);
    pii xp=getRootAndVal(x),yp=getRootAndVal(y);
    int xrank=data[xp.fst].rank,yrank=data[yp.fst].rank;
    int newrank;
    if (xrank<yrank) {
    	swap(xp,yp);
    	newrank=yrank;
    }
    else if (xrank==yrank) newrank=xrank+1;
    else newrank=xrank;
    int xr=xp.fst,yr=yp.fst;
    if (xr==yr) {
      basis.add(xp.snd^yp.snd^d);
    }
    else {
    	data.modify(xr, {xr, 0, newrank});
      data.modify(yr, {xr, xp.snd^yp.snd^d, 0});
    }
  }
  int query(int x, int y, Basis &basis) {
    pii xp=getRootAndVal(x),yp=getRootAndVal(y);
    int seed=xp.snd^yp.snd;
    int ans=basis.min_xor(seed);
    //printf("seed:%d ans:%d\n",seed,ans);
    return ans;
  }
  int getts() {
    return data.ts;
  }
  void rollback(int ts) {
    data.rollback(ts);
  }
};

typedef struct _edge {
  int x,y,d,ad,rm;
} edge_t;

const int mn=200000+1;
const int me=200000*2;
edge_t vedge[me];
const int UNDEF=-3;

const char ADDED=1,REMOVED=2,ASK=3;
template<int size> class DivConquerQueryOffline {
public:
  typedef int RESULT;
  typedef struct _OPER {
    char type;
    int x,y,ei;
  } OPER;
  MergeRankRollback<size> mr;
  RESULT vresult[size];
  OPER voper[size+1];
  int askCount[size+2];
  int numOper=1; // 0 is reserved for all queries before modify
  DivConquerQueryOffline() {
  	memset(askCount,0,sizeof askCount);
  }
  void addOper(OPER oper) {
  	askCount[numOper+1]=askCount[numOper]+(oper.type==ASK?1:0);
    voper[numOper]=oper;
    numOper++;
  }
  void divconq(int l, int r, Basis basis) {
    // We have ADDED_EDGES in [0,l] minus removed edges in [l+1,r-1]
    // [0,l] - [0,r-1]
    //printf("l:%d r:%d\n",l,r);
    //assert(l<r);
    if (askCount[r]==askCount[l]) return;
    if (l+1==r) {
      auto &op=voper[l];
      if (op.type==ASK) {
        vresult[l]=mr.query(op.x, op.y, basis);
        //printf("res:%d. %d %d\n",vresult[l],op.x,op.y);
      }
    }
    else {
      int mid=(l+r)>>1;
      int oldts=mr.getts();
      //printf("l:%d r:%d oldts:%d\n",l,r,oldts);
      // Add REMOVED in [mid,r-1] that are ADDED in [0,l]
      // [0,l] - [0,r-1] to
      // [0,l] - [0,mid-1]
      Basis childBasis=basis;
      for (int qi=mid;qi<=r-1;qi++) {
        auto &oper=voper[qi];
        if (qi==0) continue;
        if (oper.type == REMOVED) {
          auto &edge=vedge[oper.ei];
          //printf("Considering: %d. %d %d. ad:%d\n",qi,edge.x,edge.y,edge.ad);
          if (0<=edge.ad&&edge.ad<=l) mr.addEdge(edge.x,edge.y,edge.d,childBasis);
        }
      }
      // [0,l] - [0,mid-1]
      divconq(l,mid, childBasis);
      mr.rollback(oldts);
      //printf("rollback to l:%d r:%d\n",l,r);
      childBasis=basis;
      // Add ADDED from [l+1,mid] that are not REMOVED in [mid,r)
      // Don't Add REMOVED in [l+1,mid] that are ADDED in [0,mid]
      // [0,l] - [0,r-1] to
      // [0,mid] - [0,r-1]
      for (int qi=l+1;qi<=mid;qi++) {
      	if (qi==0) continue;
        auto &oper=voper[qi];
        //if (mid==4&&r==6) printf("Consider: qi:%d\n",qi);
        if (oper.type == ADDED) {
          auto &edge=vedge[oper.ei];
          if (edge.rm==UNDEF||edge.rm>=r) mr.addEdge(edge.x,edge.y,edge.d,childBasis);
        }
        /*else if (oper.type==REMOVED){
          auto &edge=vedge[oper.ei];
          if (0<=edge.ad&&edge.ad<=mid) mr.addEdge(edge.x,edge.y,edge.d,childBasis);
        }*/
      }
      // [0,mid] - [mid+1,r-1]
      divconq(mid,r,childBasis);
      //mr.rollback(oldts);
      //printf("rollback to l:%d r:%d oldts:%d\n",l,r,oldts);
    }
  }
};

int nume=0;
map<int,int> e2i[mn];
inline int adde(int x, int y, int d, int addqi) {
  vedge[nume]={x,y,d,addqi,UNDEF};
  e2i[x][y]=nume;
  return nume++;
}
inline int gei(int x, int y) {
  return e2i[x][y];
}
DivConquerQueryOffline<mn> dc;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dc.vresult,-1,sizeof dc.vresult);
  int n=rint(); int m=rint();
  bitset<mn> initialEdges;
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(),d=rint(); if (x>y) swap(x,y);
    int ei=adde(x,y,d,0);
  }

  int qn=rint();
  for (int qi=1;qi<=qn;qi++) {
    int t=rint();
    int x=rint(); int y=rint();
    if (x>y) swap(x,y);
    if (t==1) {
      int d=rint();
      int ei=adde(x,y,d,qi);
      dc.addOper({ADDED, UNDEF, UNDEF, ei});
      //printf("x:%d y:%d d:%d\n",x,y,d);
    }
    else if (t==2) {
      int ei=gei(x,y);
      //printf("qi:%d ei:%d\n",qi,ei);
      vedge[ei].rm=qi;
      if (ei<m) initialEdges[ei]=true;
      dc.addOper({REMOVED, UNDEF, UNDEF, ei});
    }
    else {
      dc.addOper({ASK, x, y, UNDEF});
    }
  }
  Basis basis;
  for (int ei=0;ei<m;ei++) {
    if (!initialEdges[ei]) {
      auto &edge=vedge[ei];
      dc.mr.addEdge(edge.x,edge.y,edge.d,basis);
      //printf("Adding %d %d %d\n",edge.x,edge.y,edge.d);
    }
  }
  dc.divconq(0,qn+1,basis);
  for (int qi=1;qi<=qn;qi++) {
    int ans=dc.vresult[qi];
    if (ans!=-1) printf("%d\n",dc.vresult[qi]);
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