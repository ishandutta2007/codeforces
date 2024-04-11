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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;

int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const bool DBG=0;

const int mn=(1e5)+4;
vi g[mn];
int v2treesz[mn];
int e2cross[mn];
pii ve[mn];

void fail(string s) {
  if(DBG) printf("%s\n",s.c_str());
  printf("NO\n");
  exit(0);
}

int getxe(int x, int ei) {
  return ve[ei].fst==x?ve[ei].snd:ve[ei].fst;
}

int n;
int dfs1(int x, int p) {
  int nodes=1;
  for (auto &ei:g[x]) {
    int y=getxe(x,ei);
    if (y==p) continue;
    int under=dfs1(y,x);
    e2cross[ei]=min(under,n-under);
    if (DBG) printf("ei:%d x:%d y:%d under:%d above:%d cross:%d\n",ei,x,y,under,n-under,e2cross[ei]);
    nodes+=under;
  }
  return v2treesz[x]=nodes;
}

void subtr(ll k) {
  vpii vcrosse(n-1);
  for (int ei=0;ei<n-1;ei++) vcrosse[ei]=MP(e2cross[ei], ei);
  sort(vcrosse.begin(),vcrosse.end(),greater<pii>());
  int imin=0,imax=n+1;
  while(imin<imax) {
    int imid=(imin+imax)/2;
    ll sum=0;
    for (auto &w:vcrosse) {
      int got=w.fst; if (got > imid) got -= ((got-imid)/2)*2;
      sum+=got;
      if (sum>=k) break;
    }
    if (sum < k) imin=imid+1;
    else imax=imid;
  }
  {
    int imid=imin;
    ll sum=0;
    for (auto &w:vcrosse) {
      int got=w.fst; if (got > imid) got -= ((got-imid)/2)*2;
      w.fst=got;
      sum+=got;
      if (DBG) printf("Orig w:%d ei:%d x:%d y:%d\n",w.fst,w.snd,ve[w.snd].fst,ve[w.snd].snd);
    }
    if (DBG) printf("imid:%d sum:%lld\n",imid,sum);
    sort(vcrosse.begin(),vcrosse.end(),greater<pii>());
    for (auto &w:vcrosse) {
      if (sum>k && w.fst>=2) {
        w.fst-=2;
        sum-=2;
      }
      if (DBG) printf("Adju w:%d ei:%d x:%d y:%d\n",w.fst,w.snd,ve[w.snd].fst,ve[w.snd].snd);
    }
    if (sum!=k) fail("sum!=k");
    for (auto &w:vcrosse) e2cross[w.snd]=w.fst;
  }
}

using ValType=int;

struct Node {
  Node() {};
  Node(ValType const & _val): val(_val) {};
  Node(Node *_prev, Node *_next, ValType const & _val): prev(_prev),next(_next),val(_val) {};
  Node *prev = NULL;
  Node *next = NULL;
  ValType val=-1;
};

class LinkedList {
public:
  LinkedList() {
    head = new Node();
    tail = new Node();
    head->next=tail;
    tail->prev=head;
  }
  void check() {
    if (!DBG) return;
    assert(head->next->prev == head);
    Node *node=head->next;
    while(node!=tail) {
      assert(node->prev->next == node);
      node=node->next;
    }
    assert(node->prev->next == node);
  }
  void appendBack(LinkedList const & b) {
    b.head->next->prev = tail->prev;
    tail->prev->next = b.head->next;
    delete tail;
    tail=b.tail;
    size += b.size;
    if (DBG) check();
  }
  ValType popBack() {
    assert(size>0);
    size--;
    Node *node=tail->prev;
    ValType val=node->val;
    node->prev->next=node->next;
    node->next->prev=node->prev;
    delete node;
    if (DBG) check();
    return val;
  }
  void insBack(ValType const & val) {
    size++;
    Node *last=tail->prev;
    Node *node = new Node(last,tail,val);
    last->next=node;
    tail->prev=node;
    if (DBG) check();
  }

  bool operator< (LinkedList const & b) const {
    if (size==b.size) return (head<b.head);
    return (size<b.size);
  }
  int size=0;
  Node *head = NULL;
  Node *tail = NULL;
};

vpii vfinalans;

LinkedList make(int x, int p, int pei) {
  int overNeed=(pei==-1)?0:e2cross[pei];
  int underSupply=1;
  for (auto &ei:g[x]) {
    int y=getxe(x,ei); if (y==p) continue;
    underSupply+=e2cross[ei];
  }
  LinkedList selfList; selfList.insBack(x);
  priority_queue<LinkedList> pq; pq.push(selfList);
  for (auto &ei:g[x]) {
    int y=getxe(x,ei);
    if (y==p) continue;
    pq.push(make(y,x,ei));
  }
  if (pq.size()>=2) {
    while(underSupply > overNeed) {
      LinkedList l0=pq.top(); pq.pop();
      LinkedList l1=pq.top(); pq.pop();
      if (l0.size == 0 || l1.size == 0) fail("Must pair up but cannot in PQ loop");
      int v0=l0.popBack();
      int v1=l1.popBack();
      pq.push(l0); pq.push(l1);
      vfinalans.PB(MP(v0,v1));
      underSupply-=2;
      if (DBG) {printf("At root %d, Pair %d %d\n",x,v0,v1);}
    }
  }

  if (underSupply != overNeed) {
    if (DBG) {
      printf("overNeed:%d underSupply:%d\n",overNeed,underSupply);
    }
    fail("underSupply != overNeed at vertex " + to_string(x));
  }
  LinkedList retList;
  while(!pq.empty()) {
    LinkedList l=pq.top(); pq.pop();
    retList.appendBack(l);
  }
  return retList;
}

int32_t main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll k;
  cin>>n>>k;
  for (int ei=0;ei<n-1;ei++) {
    int x,y; cin>>x>>y;
    ve[ei]=MP(x,y);
    g[x].PB(ei); g[y].PB(ei);
  }
  dfs1(1,-1);
  subtr(k);
  make(1,-1,-1);
  printf("YES\n");
  for (auto &w:vfinalans) {
    printf("%d %d\n",w.fst,w.snd);
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