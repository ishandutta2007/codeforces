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


class HeavyLight2NoRecursion {

    // true - values on vertices, false - values on edges
    bool VALUES_ON_VERTICES = false;

    // Modify the following 6 methods to implement your custom operations on the tree.
    // This example implements Add/Max operations. Operations like Add/Sum, Set/Max can also be implemented.
    int modifyOperation(int x, int y) {
      return x + y;
    }

    // query (or combine) operation
    int queryOperation(int leftValue, int rightValue) {
      return leftValue+rightValue;
    }

    int deltaEffectOnSegment(int delta, int segmentLength) {
      if (delta == getNeutralDelta()) return getNeutralDelta();
      // Here you must write a fast equivalent of following slow code:
      // int result = delta;
      // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
      // return result;
      return delta*segmentLength;
    }

    int getNeutralDelta() {
      return 0;
    }

    int getInitValue() {
      return 0;
    }

    int getNeutralValue() {
      return 0;
    }

    // generic code
    int joinValueWithDelta(int value, int delta) {
      if (delta == getNeutralDelta()) return value;
      return modifyOperation(value, delta);
    }

    int joinDeltas(int delta1, int delta2) {
      if (delta1 == getNeutralDelta()) return delta2;
      if (delta2 == getNeutralDelta()) return delta1;
      return modifyOperation(delta1, delta2);
    }

    vector<vector<int> > value;
    int** delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
    int** len;

    vector<vector<int> > tree;
    int* size;
    int* parent;
    int* tin;
    int* tout;
    int time=0;
    int* path;
    int* pathSize;
    int* pathPos;
    int* pathRoot;
    int pathCount=0;
public:
    HeavyLight2NoRecursion(vector<vector<int> > tree) {
      this->tree = tree;
      int n = tree.size();

      size = new int[n];
      parent = new int[n];
      tin = new int[n];
      tout = new int[n];
      calcSizeParentTinTout(0);

      path = new int[n];
      pathSize = new int[n]; fill(pathSize,pathSize+n,0);
      pathPos = new int[n];
      pathRoot = new int[n];
      buildPaths(0);

      value.resize(pathCount);
      delta = new int*[pathCount];
      len = new int*[pathCount];

      for (int i = 0; i < pathCount; i++) {
        int m = pathSize[i];

        value[i].resize(2*m);
        for (int j = 0; j < m; j++)
          value[i][j + m] = getInitValue();
        for (int j = 2 * m - 1; j > 1; j -= 2)
          value[i][j >> 1] = queryOperation(value[i][j], value[i][j ^ 1]);

        delta[i] = new int[2 * m];
        fill(delta[i], delta[i]+(2*m), getNeutralDelta());

        len[i] = new int[2 * m];
        fill(len[i]+m, len[i]+(2*m), 1);
        for (int j = 2 * m - 1; j > 1; j -= 2)
          len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
      }
    }

    void calcSizeParentTinTout(int root) {
      int n = tree.size();
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
        if (curEdge[u] < tree[u].size()) {
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
      int n = tree.size();
      int* curEdge = new int[n]; fill(curEdge,curEdge+n,0);
      int* _stackPath = new int[n];
      int* _stack = new int[n];
      _stack[0] = root;
      _stackPath[0] = newPath(root);
      for (int top = 0; top >= 0; ) {
        int u = _stack[top];
        int path = _stackPath[top];
        if (curEdge[u] == 0) {
          this->path[u] = path;
          pathPos[u] = pathSize[path]++;
        }
        if (curEdge[u] < tree[u].size()) {
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
      this->path[u] = path;
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
        value[path][x >> 1] = joinValueWithDelta0(path, x >> 1);
        delta[path][x] = joinDeltas(delta[path][x], delta[path][x >> 1]);
        delta[path][x ^ 1] = joinDeltas(delta[path][x ^ 1], delta[path][x >> 1]);
        delta[path][x >> 1] = getNeutralDelta();
      }
    }

    int joinValueWithDelta0(int path, int i) {
      return joinValueWithDelta(value[path][i], deltaEffectOnSegment(delta[path][i], len[path][i]));
    }

    int queryPath(int path, int from, int to) {
      from += value[path].size() >> 1;
      to += value[path].size() >> 1;
      pushDelta(path, from);
      pushDelta(path, to);
      int res = getNeutralValue();
      for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
        if ((from & 1) != 0)
          res = queryOperation(res, joinValueWithDelta0(path, from));
        if ((to & 1) == 0)
          res = queryOperation(res, joinValueWithDelta0(path, to));
      }
      return res;
    }

    void modifyPath(int path, int from, int to, int delta) {
      from += value[path].size() >> 1;
      to += value[path].size() >> 1;
      pushDelta(path, from);
      pushDelta(path, to);
      int ta = -1;
      int tb = -1;
      for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
        if ((from & 1) != 0) {
          this->delta[path][from] = joinDeltas(this->delta[path][from], delta);
          if (ta == -1)
            ta = from;
        }
        if ((to & 1) == 0) {
          this->delta[path][to] = joinDeltas(this->delta[path][to], delta);
          if (tb == -1)
            tb = to;
        }
      }
      for (int i = ta; i > 1; i >>= 1)
        value[path][i >> 1] = queryOperation(joinValueWithDelta0(path, i), joinValueWithDelta0(path, i ^ 1));
      for (int i = tb; i > 1; i >>= 1)
        value[path][i >> 1] = queryOperation(joinValueWithDelta0(path, i), joinValueWithDelta0(path, i ^ 1));
    }

    bool isAncestor(int p, int ch) {
      return tin[p] <= tin[ch] && tout[ch] <= tout[p];
    }

    int query(int a, int b) {
      int res = getNeutralValue();
      for (int root; !isAncestor(root = pathRoot[path[a]], b); a = parent[root])
        res = queryOperation(res, queryPath(path[a], 0, pathPos[a]));
      for (int root; !isAncestor(root = pathRoot[path[b]], a); b = parent[root])
        res = queryOperation(res, queryPath(path[b], 0, pathPos[b]));
      if (!VALUES_ON_VERTICES && a == b)
        return res;
      return queryOperation(
              res,
              queryPath(path[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
                        max(pathPos[a], pathPos[b])));
    }

    void modify(int a, int b, int delta) {
      for (int root; !isAncestor(root = pathRoot[path[a]], b); a = parent[root])
        modifyPath(path[a], 0, pathPos[a], delta);
      for (int root; !isAncestor(root = pathRoot[path[b]], a); b = parent[root])
        modifyPath(path[b], 0, pathPos[b], delta);
      if (!VALUES_ON_VERTICES && a == b)
        return;
      modifyPath(path[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
                 max(pathPos[a], pathPos[b]), delta);
    }
};

vector<vector<int> > g;
const int mn=1e5+2;
int vs[mn],vt[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  g.resize(n);
  for (int i=1;i<n;i++) {
    int x=rint()-1,y=rint()-1;
    vs[i]=x;vt[i]=y;
    g[x].PB(y); g[y].PB(x);
  }
  HeavyLight2NoRecursion hl = HeavyLight2NoRecursion(g);
  int k=rint();
  for (int i=0;i<k;i++) {
    int x=rint()-1,y=rint()-1;
    hl.modify(x,y,1);
  }
  for (int i=1;i<n;i++) {
    unsigned int ans=hl.query(vs[i],vt[i]);
    printf("%u ",ans);
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