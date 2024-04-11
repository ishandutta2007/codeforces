#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readInt()
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}


vector<vector<int> > tree;

/*
    // FAST INIT ON EDGES
    if (hl.isAncestor(y,x)) inp[x]=cost; else inp[y]=cost;
    hl.initInput();
*/
typedef struct STTV {
  int val[10];
  int len;
} STV;

typedef char STD;
const int mn=100002;
vector<int> inp[mn];
class HeavyLight2NoRecursion {

  // true - values on vertices, false - values on edges
  bool VALUES_ON_VERTICES = true;

  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return x;
  }

  // query (or combine) operation
  STV queryOperation(STV leftValue, STV rightValue) {
    int tmp[20];
    int idx=0;
    for (int i=0;i<leftValue.len;i++) tmp[idx++]=leftValue.val[i];
    for (int i=0;i<rightValue.len;i++) tmp[idx++]=rightValue.val[i];
    sort(tmp,tmp+idx);
    int len=min(10,idx);
    STV ans;
    ans.len=len;
    memcpy(ans.val,tmp,len*sizeof(int));
    return ans;
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    return 0;
    /*if (isNeutralDelta(delta)) return getNeutralDelta();
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    STD ans;
    ans.val=delta.val*segmentLength;
    return ans;*/
  }

  STD initNeutralDelta() {
    STD ans=0;
    return ans;
  }

  bool isNeutralDelta(STD delta) {
    return true;
  }

  STV getInitValue(int vtx) {
    STV ans;
    int len=inp[vtx].size();
    ans.len=len;
    for (int i=0;i<len;i++) ans.val[i]=inp[vtx][i];
    return ans;
  }

  STV getNeutralValue() {
    STV ans;
    ans.len=0;
    return ans;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return 0;
  }

  STV joinValueWithDelta(STV value, STD delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }


  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  STV** vvalue;
  STD** vdelta; // vdelta[i] affects vvalue[i], vdelta[2*i+1] and vdelta[2*i+2]
  int** len;

  int* size;
  int* parent;
  int* tin;
  int* tout;
  int time=0;
  int* vpath;
  int* pathSize;
  int* pathPos;
  int* pathRoot;
  int pathCount=0;
public:
  HeavyLight2NoRecursion() {
  }
  void initInput() {
    _cache_neutral_delta = initNeutralDelta();
    int n = (int)tree.size();

    size = new int[n];
    parent = new int[n];
    tin = new int[n]; 
    tout = new int[n]; 
    calcSizeParentTinTout(0);

    vpath = new int[n]; 
    pathSize = new int[n]; fill(pathSize,pathSize+n,0);
    pathPos = new int[n]; 
    pathRoot = new int[n]; 
    buildPaths(0);

    vvalue = new STV*[pathCount];
    vdelta = new STD*[pathCount];
    len = new int*[pathCount];

    for (int i = 0; i < pathCount; i++) {
      int m = pathSize[i];

      vvalue[i] = new STV[2*m];
    }
    for (int vtx=0;vtx<n;vtx++) {
      int path_idx=vpath[vtx];
      int m = pathSize[path_idx];
      int j=pathPos[vtx];
      vvalue[path_idx][j+m] = getInitValue(vtx);
    }
    for (int i = 0; i < pathCount; i++) {
      int m = pathSize[i];
      for (int j = 2 * m - 1; j > 1; j -= 2)
        vvalue[i][j >> 1] = queryOperation(vvalue[i][j], vvalue[i][j ^ 1]);

      vdelta[i] = new STD[2 * m];
      for (int j=0;j<2*m;j++) vdelta[i][j]=getNeutralDelta();

      len[i] = new int[2 * m];
      fill(len[i]+m, len[i]+(2*m), 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  void calcSizeParentTinTout(int root) {
    int n = (int)tree.size();
    int* curEdge = new int[n]; fill(curEdge,curEdge+n,0);
    int* _stack = new int[n];
    _stack[0] = root;
    parent[root] = -1;
    for (int top = 0; top >= 0; ) {
      int u = _stack[top];
      if (curEdge[u] == 0) {
        tin[u] = time++;
        size[u] = 1;
      }
      if (curEdge[u] < (int)tree[u].size()) {
        int v = tree[u][curEdge[u]++];
        if (curEdge[v] == 0) {
          _stack[++top] = v;
          parent[v] = u;
        }
      } else {
        --top;
        if (parent[u] != -1)
          size[parent[u]] += size[u];
        tout[u] = time++;
      }
    }
  }

  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }

  void buildPaths(int root) {
    int n = (int)tree.size();
    int* curEdge = new int[n]; fill(curEdge,curEdge+n,0);
    int* _stackPath = new int[n];
    int* _stack = new int[n];
    _stack[0] = root;
    _stackPath[0] = newPath(root);
    for (int top = 0; top >= 0; ) {
      int u = _stack[top];
      int path = _stackPath[top];
      if (curEdge[u] == 0) {
        this->vpath[u] = path;
        pathPos[u] = pathSize[path]++;
      }
      if (curEdge[u] < (int)tree[u].size()) {
        int v = tree[u][curEdge[u]++];
        if (curEdge[v] == 0) {
          _stack[++top] = v;
          _stackPath[top] = 2 * size[v] >= size[u] ? path : newPath(v);
        }
      } else {
        --top;
      }
    }
  }

  void buildPaths(int u, int path) {
    this->vpath[u] = path;
    pathPos[u] = pathSize[path]++;
    for (int v : tree[u]) {
      if (v != parent[u])
        buildPaths(v, 2 * size[v] >= size[u] ? path : newPath(v));
    }
  }

  void pushDelta(int path, int i) {
    int d = 0;
    for (; (i >> d) > 0; d++)
      ;
    for (d -= 2; d >= 0; d--) {
      int x = i >> d;
      vvalue[path][x >> 1] = joinValueWithDelta0(path, x >> 1);
      vdelta[path][x] = joinDeltas(vdelta[path][x], vdelta[path][x >> 1]);
      vdelta[path][x ^ 1] = joinDeltas(vdelta[path][x ^ 1], vdelta[path][x >> 1]);
      vdelta[path][x >> 1] = getNeutralDelta();
    }
  }

  STV joinValueWithDelta0(int path, int i) {
    return joinValueWithDelta(vvalue[path][i], deltaEffectOnSegment(vdelta[path][i], len[path][i]));
  }

  STV queryPath(int path, int from, int to) {
    from += pathSize[path];
    to += pathSize[path];
    pushDelta(path, from);
    pushDelta(path, to);
    STV res = getNeutralValue();
    for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
      if ((from & 1) != 0)
        res = queryOperation(res, joinValueWithDelta0(path, from));
      if ((to & 1) == 0)
        res = queryOperation(res, joinValueWithDelta0(path, to));
    }
    return res;
  }

  void modifyPath(int path, int from, int to, STD delta) {
    from += pathSize[path];
    to += pathSize[path];
    pushDelta(path, from);
    pushDelta(path, to);
    int ta = -1;
    int tb = -1;
    for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
      if ((from & 1) != 0) {
        this->vdelta[path][from] = joinDeltas(this->vdelta[path][from], delta);
        if (ta == -1)
          ta = from;
      }
      if ((to & 1) == 0) {
        this->vdelta[path][to] = joinDeltas(this->vdelta[path][to], delta);
        if (tb == -1)
          tb = to;
      }
    }
    for (int i = ta; i > 1; i >>= 1)
      vvalue[path][i >> 1] = queryOperation(joinValueWithDelta0(path, i), joinValueWithDelta0(path, i ^ 1));
    for (int i = tb; i > 1; i >>= 1)
      vvalue[path][i >> 1] = queryOperation(joinValueWithDelta0(path, i), joinValueWithDelta0(path, i ^ 1));
  }

  bool isAncestor(int p, int ch) {
    return tin[p] <= tin[ch] && tout[ch] <= tout[p];
  }

  STV query(int a, int b) {
    STV res = getNeutralValue();
    for (int root; !isAncestor(root = pathRoot[vpath[a]], b); a = parent[root])
      res = queryOperation(res, queryPath(vpath[a], 0, pathPos[a]));
    for (int root; !isAncestor(root = pathRoot[vpath[b]], a); b = parent[root])
      res = queryOperation(res, queryPath(vpath[b], 0, pathPos[b]));
    if (!VALUES_ON_VERTICES && a == b)
      return res;
    return queryOperation(
        res,
        queryPath(vpath[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
            max(pathPos[a], pathPos[b])));
  }

  void modify(int a, int b, STD delta) {
    for (int root; !isAncestor(root = pathRoot[vpath[a]], b); a = parent[root])
      modifyPath(vpath[a], 0, pathPos[a], delta);
    for (int root; !isAncestor(root = pathRoot[vpath[b]], a); b = parent[root])
      modifyPath(vpath[b], 0, pathPos[b], delta);
    if (!VALUES_ON_VERTICES && a == b)
      return;
    modifyPath(vpath[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
        max(pathPos[a], pathPos[b]), delta);
  }
};

HeavyLight2NoRecursion hl;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),q=readInt();
  tree.resize(n);
  for (int i=0;i<n-1;i++) {
    int x=readInt()-1,y=readInt()-1;
    tree[x].PB(y); tree[y].PB(x);
    //printf("x:%d y:%d\n",x,y);
  }
  for (int i=1;i<=m;i++) {
    int c=readInt()-1;
    inp[c].PB(i);
    //printf("c:%d i:%d\n",c,i);
  }
  for (int c=0;c<n;c++) {
    int sz=inp[c].size();
    if (sz>0) {
      sort(inp[c].begin(),inp[c].end());
      inp[c].resize(min(sz,10));
    }
  }
  hl.initInput();
  for (int i=0;i<q;i++) {
    int x=readInt()-1,y=readInt()-1,a=readInt();
    //printf("x:%d y:%d a:%d\n",x,y,a);
    STV got=hl.query(x,y);
    int len=min(a,got.len);
    printf("%d ",len);
    for (int i=0;i<len;i++) {
      printf("%d ",got.val[i]);
    }
    printf("\n");
  }
}