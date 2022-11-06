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

/*
const int MAXSZ=(244)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 3) & ~0x03;
  //preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
*/
/*
class MemoryVector {
public:
  static const unsigned int INPUT_WIDTH=17; // Bits to fit the input
  static const unsigned int INT_WIDTH=32;
  static const unsigned int LOG_INT_WIDTH=5;
  vector<unsigned int> v={0};
  unsigned int head_idx=0,_size=0;
  void set(unsigned int idx, unsigned int inp) {
    idx*=17;
    unsigned int quo=idx>>LOG_INT_WIDTH, rem=idx&(INT_WIDTH-1U);
    v[quo]&=~(((1U<<INPUT_WIDTH)-1)<<rem);
    v[quo]|=(inp<<rem);
    int taken_bits = INT_WIDTH - rem;
    if (taken_bits < INPUT_WIDTH) {
      v[quo+1]&=~(((1U<<INPUT_WIDTH)-1)>>taken_bits);
      v[quo+1]|=(inp>>taken_bits);
    }
  }
  void push_back(unsigned int inp) {
    int idx=head_idx;
    unsigned int quo=idx>>LOG_INT_WIDTH, rem=idx&(INT_WIDTH-1U);
    if (v.size()<=quo+1) v.PB(0);
    v[quo]|=(inp<<rem);
    int taken_bits = INT_WIDTH - rem;
    if (taken_bits < INPUT_WIDTH) {
      v[quo+1]=(inp>>taken_bits);
    }
    head_idx+=INPUT_WIDTH;
    _size++;
  }
  unsigned int operator [](unsigned int idx) const {
    idx*=INPUT_WIDTH;
    unsigned int quo=idx>>LOG_INT_WIDTH, rem=idx&(INT_WIDTH-1U);
    unsigned int ans=v[quo]>>rem;
    int taken_bits = INT_WIDTH - rem;
    if (taken_bits < INPUT_WIDTH) {
      ans|=v[quo+1]<<taken_bits;
    }
    return ans&((1U<<INPUT_WIDTH) - 1U);
  }
  int size() {
    return _size;
  }
};

void test() {
  vector<unsigned int> v;
  MemoryVector g;
  srand(clock());
  for (int k=0;k<30000;k++) {
    assert(g.v.size()<= (v.size()*17)/32+3);
    assert(v.size()==g.size());
    int t=rand()%3;
    if (t==1) {
      int x=rand()%100001;
      //printf("Push x:%d\n",x);
      v.PB(x); g.PB(x);
    }
    else if (t==2) {
      int vsz=v.size(); int x=rand()%100001;
      if (vsz>0) {
        int i=rand()%vsz;
        v[i]=x;
        g.set(i,x);
        //rintf("Get i:%d vi:%u gi:%u\n",i,v[i],g[i]);
        assert(v[i]==g[i]);
      }
    }
    else {
      int vsz=v.size();
      if (vsz>0) {
        int i=rand()%vsz;
        //rintf("Get i:%d vi:%u gi:%u\n",i,v[i],g[i]);
        assert(v[i]==g[i]);
      }
    }
  }
}
*/

const int SZ = 100000+1;


int tmp[SZ];
struct Node1 {
  set<int> s;
  void upd(int x) {
    s.insert(x);
  }
  bool query(int x1, int x2) {
    auto it=s.lower_bound(x1);
    return it!=s.end()&&(*it)<=x2;
  }
};



struct Node2 {
    Node1 seg;
    Node2* c[2];
    void upd(int x, int y, int L = 0, int R = SZ-1) { // add v
        seg.upd(y);
        if (L == x && R == x) {
            return;
        }
        int M = (L+R)/2;
        if (x <= M) {
            if (!c[0]) c[0] = new Node2();
            c[0]->upd(x,y,L,M);
        } else {
            if (!c[1]) c[1] = new Node2();
            c[1]->upd(x,y,M+1,R);
        }
    }
    
    bool query(int x1, int x2, int y1, int y2, int L = 0, int R = SZ-1) { // query sum of rectangle
        if (x1 <= L && R <= x2) return seg.query(y1,y2);
        if (x2 < L || R < x1) return false;
        int M = (L+R)/2;
        if (c[0]) if(c[0]->query(x1,x2,y1,y2,L,M)) return true;
        if (c[1]) if(c[1]->query(x1,x2,y1,y2,M+1,R)) return true;
        return false;
    }
};

/*
struct Node3 {
    Node2 seg;
    Node3* c[2];
    void upd(int x, int y, int z, int L = 0, int R = SZ-1) { // add v
        seg.upd(y,z);
        if (L == x && R == x) {
            return;
        }
        int M = (L+R)/2;
        if (x <= M) {
            if (!c[0]) c[0] = new Node3();
            c[0]->upd(x,y,z,L,M);
        } else {
            if (!c[1]) c[1] = new Node3();
            c[1]->upd(x,y,z,M+1,R);
        }
    }
    
    bool query(int x1, int x2, int y1, int y2, int z1, int z2, int L = 0, int R = SZ-1) { // query sum of rectangle
        if (x1 <= L && R <= x2) return seg.query(y1,y2,z1,z2);
        if (x2 < L || R < x1) return false;
        int M = (L+R)/2;
        if (c[0]) if(c[0]->query(x1,x2,y1,y2,z1,z2,L,M)) return true;
        if (c[1]) if(c[1]->query(x1,x2,y1,y2,z1,z2,M+1,R)) return true;
        return false;
    }
};
*/
/*
const int mn=50;
bitset<mn+4> a[mn+4];
void test() {
  for (int x=0;x<mn+4;x++) a[x].reset();
  Node2 *root = new Node2;
  srand(clock());
  for (int k=0;k<1000;k++) {
    int x=rand()%mn,y=rand()%mn;
    root->upd(x,y); a[x][y]=true;
    int x1=rand()%mn,x2=rand()%mn; if (x1>x2) swap(x1,x2);
    int y1=rand()%mn,y2=rand()%mn; if (y1>y2) swap(y1,y2);
    bool got=root->query(x1,x2,y1,y2);
    bool bf=0;
    for (int x=x1;x<=x2;x++) for (int y=y1;y<=y2;y++) {
      if (a[x][y]) {bf=1; break;}
    }
    if (bf!=got) {
      printf("WRONG\n");
      exit(0);
    }
  }
}
*/
int lim[3];
int vh[3],vl[3];
struct Query {
  int p[3]; int qi;
};
bool cmp(const Query &a, const Query &b) {
  return a.p[0]<b.p[0];
}
bool cmprev(const Query &a, const Query &b) {
  return a.p[0]>b.p[0];
}
Node2 root,newroot;
const int mn=1e5+4;
vector<Query> vc[3];
vector<Query> vq[3];
const int EQ=0,LESS=1,GR=2;
const char OPEN=1,CLOSED=2,UNKNOWN=3;
char vfinal[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int i=0;i<800;i++) test();
  //exit(0);
  for (int d=0;d<3;d++) lim[d]=rint();
  int n=rint(),m=rint(),k=rint();
  for (int d=0;d<3;d++) {vl[d]=INT_MAX; vh[d]=INT_MIN;}
  for (int i=0;i<n;i++) {
    for (int d=0;d<3;d++) {
      int got=rint();
      chkmin(vl[d],got);
      chkmax(vh[d],got);
    }
  }
  for (int i=0;i<m;i++) {
    Query q;
    for (int d=0;d<3;d++) q.p[d]=rint();
    if (q.p[0]<vl[0]) vc[LESS].PB(q);
    else if (q.p[0]>vh[0]) vc[GR].PB(q);
    else vc[EQ].PB(q);
  }
  for (auto &c:vc[EQ]) {
    if (
      vl[1]<=c.p[1]&&c.p[1]<=vh[1] &&
      vl[2]<=c.p[2]&&c.p[2]<=vh[2]
    ) {
      printf("INCORRECT\n"); exit(0);
    }
  }
  sort(vc[LESS].begin(),vc[LESS].end(),cmprev);
  sort(vc[GR].begin(),vc[GR].end(),cmp);
  printf("CORRECT\n");
  for (int i=0;i<k;i++) {
    Query q; q.qi=i;
    for (int d=0;d<3;d++) q.p[d]=rint();
    if (q.p[0]<vl[0]) vq[LESS].PB(q);
    else if (q.p[0]>vh[0]) vq[GR].PB(q);
    else vq[EQ].PB(q);
  }
  sort(vq[LESS].begin(),vq[LESS].end(),cmprev);
  sort(vq[GR].begin(),vq[GR].end(),cmp);
  for (auto &c:vc[EQ]) {
    root.upd(c.p[1],c.p[2]);
  }
  for (int t=0;t<3;t++) {
    if (t==2) {
      root=newroot;
      for (auto &c:vc[EQ]) {
        root.upd(c.p[1],c.p[2]);
      }
    }
    auto it=vc[t].begin();
    //printf("t:%d\n",t);
    for (auto &q:vq[t]) {
      if (t==LESS) {
        while(it!=vc[t].end() && it->p[0]>=q.p[0]) {
          root.upd(it->p[1], it->p[2]);
          ++it;
        }
      }
      else if (t==GR) {
        while(it!=vc[t].end() && it->p[0]<=q.p[0]) {
          //printf("GR it:%d q:%d\n",it->p[0], q.p[0]);
          root.upd(it->p[1], it->p[2]);
          ++it;
        }
      }
      bool closed=false;
      for (int d=0;d<3;d++) {
        if (!(vl[d]<=q.p[d]&&q.p[d]<=vh[d])) closed=true;
      }
      bool open=true;
      if (root.query(
        min(vl[1],q.p[1]),max(vh[1],q.p[1]),
        min(vl[2],q.p[2]),max(vh[2],q.p[2])
        )) {
        open=false;
      }
      if (closed&&open) vfinal[q.qi]=UNKNOWN;
      else if (closed) vfinal[q.qi]=CLOSED;
      else vfinal[q.qi]=OPEN;
    }
  }
  for (int i=0;i<k;i++) {
    if (vfinal[i]==UNKNOWN) printf("UNKNOWN\n");
    else if (vfinal[i]==CLOSED) printf("CLOSED\n");
    else printf("OPEN\n");
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