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


/*
		// FAST INIT ON EDGES
		if (hl.isAncestor(y,x)) inp[x]=cost; else inp[y]=cost;
		hl.initInput();
*/
typedef int STV;
typedef int STD;
const int mn=1e5+4;
int inp[mn];
const int MARKED = mn;
const int NEUTRAL = 0;
class HeavyLight2NoRecursion {

	// true - values on vertices, false - values on edges
	bool VALUES_ON_VERTICES = true;

  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
  	if (y==NEUTRAL) return x;
    return y;
  }

  // query (or combine) operation
  STV queryOperation(STV leftValue, STV rightValue) {
    return max(leftValue,rightValue);
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    /*if (isNeutralDelta(delta)) return getNeutralDelta();*/
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    return delta;
  }

  STD initNeutralDelta() {
  	return NEUTRAL;
  }

  bool isNeutralDelta(STD delta) {
    return delta==NEUTRAL;
  }

	STV getInitValue(int vtx) {
		return inp[vtx];
	}

  STV getNeutralValue() {
  	return INT_MIN;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1+delta2;
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

	vector<vector<int> > tree;
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
	HeavyLight2NoRecursion(vector<vector<int> > tree) {
		_cache_neutral_delta = initNeutralDelta();
		this->tree = tree;
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
	}
	void initInput() {
		int n = (int)this->tree.size();
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




typedef struct _tri
{
  struct _tri *children[26];
  int id;
  bool mark;
} tri;

tri *getNode()
{
  tri *root = new tri;
  memset(root->children,0,sizeof (root->children));
  root->mark=false;
  return root;
}

// Trie add string
void addstr(tri *root, const char *str, int len) {
  for (int depth = 0; depth < len; depth++)
  {
    int index = str[depth]-'a';
    if (!root->children[index]) {
      root->children[index] = getNode();
    }
    root = root->children[index];
  }
  root->mark = true;
}

vector<vi> g(mn);
int id2h[mn];
int gid=0;
priority_queue<pii> pq;
void bfs(tri *root) {
	queue<tri*> q;
	q.push(root);
	root->id=gid++;
	id2h[root->id]=0;
	while(!q.empty()) {
		tri *x=q.front(); q.pop();
		int xh=id2h[x->id];
		if (x->mark) {
			pq.push(MP(xh,x->id));
			inp[x->id]=x->id - MARKED;
		}
		else {
			inp[x->id]=x->id;
		}
		for (int c=0;c<26;c++) {
			tri *y=x->children[c];
			if (y!=NULL) {
				q.push(y);
				y->id=gid++;
				id2h[y->id]=xh+1;
				g[x->id].PB(y->id); g[y->id].PB(x->id);
			}
		}
	}
}

char str[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  tri *root=getNode(); root->mark=true;
  for (int i=0;i<n;i++) {
  	scanf("%s\n",str);
  	int slen=strlen(str);
  	addstr(root,str,slen);
  }
  bfs(root);
  g.resize(gid);
  HeavyLight2NoRecursion hl(g);
  hl.initInput();
  int final=0;
  while(!pq.empty()) {
  	pii top=pq.top(); pq.pop();
  	int x=top.snd;
  	int y=hl.query(0,x);
  	//printf("x:%d y:%d\n",x,y);
  	if (y>=0) {
  		//printf("x:%d xh:%d y:%d yh:%d\n",x,id2h[x],y,id2h[y]);
  		hl.modify(y,y,-MARKED);
  		pq.push(MP(id2h[y],y));
  		// hl.modify(x,x,MARKED); // Is this needed?
  	}
  	else {
  		final+=top.fst;
  	}
  }
  printf("%d\n",final);
}