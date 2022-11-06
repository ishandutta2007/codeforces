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
const int MAXSZ=(256-16)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  //preidx+=(((int)size) + 7) & ~0x07;
  preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
//#define MAXR 20000000004
//#define MAXC 20000000004
const int mn=1e5+2;
//const int mn=12;
const int MAXR=mn,MAXC=mn;
#include <assert.h>
#include <stddef.h>
typedef unsigned int STV;
inline STV gcd2(STV X, STV Y) {
  return X+Y;
}
struct layer2_node {
  layer2_node(int low, int high)
      : low(low), high(high), lft(NULL), rht(NULL), value(0LL) {
  }

  int low;
  int high;
  layer2_node* lft;
  layer2_node* rht;
  STV value;
};

struct layer1_node {
  layer1_node() : lft(NULL), rht(NULL), l2(0, MAXC) {
  }

  layer1_node* lft;
  layer1_node* rht;
  layer2_node l2;
};

static void update2(layer2_node* node, int Q, STV K) {
  int low = node->low;
  int high = node->high;
  int mid = (low + high) / 2;
  if(low + 1 == high) {
    /* For leaf nodes we just update the value directly. */
    node->value = K;
    return;
  }

  layer2_node*& tgt = Q < mid ? node->lft : node->rht;
  if(tgt == NULL) {
    /* If there is no node on this side of the tree create a new leaf node
     * containing exactly our update point. */
    tgt = new layer2_node(Q, Q + 1);
    tgt->value = K;
  } else if(tgt->low <= Q && Q < tgt->high) {
    /* If the existing node contains our query point continue inserting there.
     */
    update2(tgt, Q, K);
  } else {
    /* Otherwise traverse down the virtual tree until the side of our query node
     * and the side of the existing node differ.  Create this node and continue
     * updating along it. */
    do {
      (Q < mid ? high : low) = mid;
      mid = (low + high) / 2;
    } while((Q < mid) == (tgt->low < mid));

    layer2_node* nnode = new layer2_node(low, high);
    (tgt->low < mid ? nnode->lft : nnode->rht) = tgt;
    tgt = nnode;

    update2(nnode, Q, K);
  }

  /* Internal nodes get updated as the gcd of its leaves. */
  node->value = gcd2(node->lft ? node->lft->value : 0,
                     node->rht ? node->rht->value : 0);
}

STV query2(layer2_node* nd, int A, int B) {
  /* The same as the level 1 queries except the interval each node represents
   * may skip some levels of the tree so we store them in the node itself. */
  if(nd == NULL || B <= nd->low || nd->high <= A) {
    return 0;
  } else if(A <= nd->low && nd->high <= B) {
    return nd->value;
  }
  return gcd2(query2(nd->lft, A, B), query2(nd->rht, A, B));
}

static void update1(layer1_node* node, int low, int high,
                    int P, int Q, STV K) {
  int mid = (low + high) / 2;

  if(low + 1 == high) {
    update2(&node->l2, Q, K);
  } else {
    layer1_node*& nnode = P < mid ? node->lft : node->rht;
    (P < mid ? high : low) = mid;
    if(nnode == NULL) {
      nnode = new layer1_node();
    }
    update1(nnode, low, high, P, Q, K);

    /* Compute what value to update with. */
    K = gcd2(node->lft ? query2(&node->lft->l2, Q, Q + 1) : 0,
             node->rht ? query2(&node->rht->l2, Q, Q + 1) : 0);
    update2(&node->l2, Q, K);
  }
}

STV query1(layer1_node* nd, int low, int high,
                 int A1, int B1, int A2, int B2) {
  /* Scan down the tree short-circuiting when we reach a node that contains
   * our entire query interval and combining the result of the level2 queries.
   */
  if(nd == NULL || B1 <= low || high <= A1) {
    return 0;
  } else if(A1 <= low && high <= B1) {
    return query2(&nd->l2, A2, B2);
  }
  int mid = (low + high) / 2;
  return gcd2(query1(nd->lft, low, mid, A1, B1, A2, B2),
              query1(nd->rht, mid, high, A1, B1, A2, B2));
}

void init(int R, int C) {
}
static layer1_node root;
void update_2dseg(int P, int Q, STV K) {
  update1(&root, 0, MAXR, P, Q, K);
}

STV calculate_2dseg(int P, int Q, int U, int V) {
  return query1(&root, 0, MAXR, P, U + 1, Q, V + 1);
}

const int segn=mn;  // array size
typedef unsigned int S;
S t[2 * mn];
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
}
//void build(S *t) {  // build the tree
//  int n=segn;
//  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
//}

void modify(int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) { // sum on interval [l, r]
  r++;
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}

void update (int pos, int l, int flag) {
  if (flag==0) {
    update_2dseg(pos, l, 0);
  }
  else {
    update_2dseg(pos, l, l-pos);
    modify(pos,pos-l);
  }
}

STV solve(int l, int r) {
  STV onedim=query(l,r);
  STV twodim=calculate_2dseg(l,0,r,l-1);
  return onedim+twodim;
}

int a[mn];
set<int> shape2pos[mn];
int vl[mn],vr[mn];
int tmp[mn];
const int vinf=mn-1;
void rm(int pos, int oldshape) {
  //printf("rm\n");
  int l=vl[pos],r=vr[pos];
  //update(root1,pos,r,0);
  update(pos,l,0);
  if (r<vinf) {
    vl[r]=l;
    update(r,pos,0);
    update(r,l,r);
  }
  if (l>0) {
    vr[l]=r;
    //update(root1,l,pos,0);
    //update(root1,l,r,l);
  }
  shape2pos[oldshape].erase(pos);
}

void ins(int pos, int newshape) {
  //printf("ins\n");
  std::pair<std::set<int>::iterator,bool> ret=shape2pos[newshape].insert(pos);
  auto it=ret.fst;
  int l=0,r=vinf;
  if (it!=shape2pos[newshape].begin()) {
    --it; l=*it; r=vr[l];
  }
  else {
    ++it;
    if (it!=shape2pos[newshape].end()) {
      r=*it;
    }
  }
  vl[pos]=l; vr[pos]=r;
  if (l>0) {
    //update(root1,l,vr[l],0);
    //update(root1,l,pos,l);
    vr[l]=pos;
  }
  if (r<vinf) {
    update(r,vl[r],0);
    update(r,pos,r);
    vl[r]=pos;
  }
  //update(root1,pos,r,pos);
  update(pos,l,pos);
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //test(); return 0;
  int n=rint(),m=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  for (int x=1;x<=n;x++) {
    shape2pos[a[x]].insert(x);
  }
  for (int x=n;x>=1;x--) {
    int val=a[x];
    int h=vinf;
    if (tmp[val]!=0) {
      h=tmp[val];
      vl[h]=x;
    }
    vr[x]=h;
    tmp[val]=x;
  }
  for (int x=1;x<=n;x++) {
    //update(root1,x,vr[x],x);
    update(x,vl[x],x);
  }
  for (int qi=0;qi<m;qi++) {
    int t=rint();
    if (t==1) {
      int pos=rint(),newshape=rint();
      //printf("pos:%d newshape:%d\n",pos,newshape);
      int oldshape=a[pos];
      if (oldshape!=newshape) {
        a[pos]=newshape;
        rm(pos, oldshape);
        ins(pos,newshape);
      }
    }
    else {
      int l=rint(),r=rint();
      //STV ans1=calculate(root1,l,r+1,r,vinf);
      STV ans2=solve(l,r);
      printf("%u\n",ans2);
    }
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