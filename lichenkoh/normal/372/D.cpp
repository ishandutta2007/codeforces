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
const int INF=1<<29;
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


/*
		// FAST INIT ON EDGE
		if (hl.isAncestor(y,x)) inp[x]=cost; else inp[y]=cost;
		hl.initInput();
*/
typedef int STV;

const int mn=100000+4;
typedef int STD;
class HeavyLight2NoRecursion {

	// true - values on vertices, false - values on edges
	bool VALUES_ON_VERTICES = true;

  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return x+y;
  }

  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
  	return l+r;
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    if (isNeutralDelta(delta)) return getNeutralDelta();
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    // STD ans;
    // ans.val=delta.val*segmentLength;
    // return ans;
    return delta*segmentLength;
  }

  STD initNeutralDelta() {
  	return 0;
  }

  bool isNeutralDelta(STD delta) {
    return delta==0;
  }

	STV getInitValue(int vtx) {
		return 0;
	}

  STV getNeutralValue() {
  	return 0;
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
	void init(vector<vector<int> > tree) {
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

	STV query(int oa, int ob) {
		int a=oa,b=ob;
		STV res = getNeutralValue();
		for (int root; !isAncestor(root = pathRoot[vpath[a]], b); a = parent[root])
			res = queryOperation(res, queryPath(vpath[a], 0, pathPos[a]));
		for (int root; !isAncestor(root = pathRoot[vpath[b]], a); b = parent[root])
			res = queryOperation(res, queryPath(vpath[b], 0, pathPos[b]));
		if (!VALUES_ON_VERTICES && a == b)
			return res;
		STV ans= queryOperation(
				res,
				queryPath(vpath[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
						max(pathPos[a], pathPos[b])));
		return ans;
	}

	void modify(int a, int b, STD delta) {
		//printf("a:%d b:%d delta:%d\n",a,b,delta);
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

vector<vector<int> > g;

// Answering LCA queries in O(1) with O(n*log(n)) preprocessing
class LcaSparseTable {
public:
	int len=0;
	int** up;
	int* tin;
	int* tout;
	int timestamp=0;
	int* vdepth;

	void dfs(vector<vector<int> > &tree, int u, int p, int depth) {
		vdepth[u] = depth;
		tin[u] = timestamp++;
		up[0][u] = p;
		for (int i = 1; i < len; i++)
			up[i][u] = up[i - 1][up[i - 1][u]];
		for (int v : tree[u])
			if (v != p)
				dfs(tree, v, u, depth+1);
		tout[u] = timestamp++;
	}

	void init(vector<vector<int> > &tree, int n, int root) {
		len = 1;
		while ((1 << len) <= n) ++len;
		up = new int*[len];
		for (int i=0;i<len;i++) {up[i]=new int[n]; memset(up[i],0,sizeof(up[i][0])*n);}
		tin = new int[n]; memset(tin,0, sizeof(tin[0])*n);
		tout = new int[n]; memset(tout,0,sizeof(tout[0]*n));
		vdepth = new int[n]; memset(vdepth,0,sizeof(vdepth[0]*n));
		dfs(tree, root, root, 0);
	}

	bool isParent(int parent, int child) {
		return tin[parent] <= tin[child] && tout[child] <= tout[parent];
	}

	pair<int,int> lca(int oa, int ob) {
		// Returns make_pair(LCA, number of edges on shortest path from a to b)
		int a=oa,b=ob;
		if (isParent(a, b))
			return MP(a, vdepth[b] - vdepth[a]);
		if (isParent(b, a))
			return MP(b, vdepth[a] - vdepth[b]);
		for (int i = len - 1; i >= 0; i--)
			if (!isParent(up[i][a], b))
				a = up[i][a];
		int ancestor=up[0][a];
		return MP(ancestor, vdepth[oa] + vdepth[ob] - (2 * vdepth[ancestor]));
	}
	int godist(int src, int dest, int dist, pii got, pii g1) {
		if (dist<=g1.snd) {
			int ans=src,i=0;
			while(dist>0) {
				if (dist&1) {
					//printf("ans:%d->%d dist:%d i:%d\n",ans,up[i][ans],dist,i);
					ans=up[i][ans];
				}
				dist>>=1; i++;
			}
			return ans;
		}
		else {
			int ans=dest,i=0;
			dist=got.snd-dist;
			//printf("dist:%d\n",dist);
			while(dist>0) {
				//printf("ans:%d->%d dist:%d i:%d\n",ans,up[i][ans],dist,i);
				if (dist&1) ans=up[i][ans];
				dist>>=1; i++;
			}
			return ans;
		}
	}
};

LcaSparseTable LCAST;
HeavyLight2NoRecursion hl;

int getzero(int from, int to) {
	pii got=LCAST.lca(from,to);
	pii g1= LCAST.lca(from,got.fst);
	int imin=0,imax=got.snd+1;
	while(imin<imax) {
		int imid=(imin+imax)>>1;
		int target=LCAST.godist(from,to,imid, got, g1);
		int hlq=hl.query(from, target);
		//printf("from:%d to:%d dist:%d target:%d hlq:%d\n",from,to,imid,target,hlq);
		if (hlq==0) imin=imid+1;
		else imax=imid;
	}
	//printf("%d->%d zero:%d\n",from,to,imin);
	return imin;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),k=readInt();
	g.resize(n);
	for (int i=0;i<n-1;i++)	{
		int a=readInt()-1,b=readInt()-1;
		g[a].PB(b);
		g[b].PB(a);
		//dbg("a:%d b:%d\n",a,b);
	}
	LCAST.init(g, (int)g.size(), 0);
	hl.init(g);
	int final=1;
	int live=0;
	int l=0;
	for (int r=1;r<n;r++) {
		live+=getzero(r,r-1);
		hl.modify(r,r-1,1);
		//printf("r:%d l:%d live:%d hlq3:%d\n",r,l,live,hl.query(3,3));
		while(l<r&&live>k) {
			hl.modify(l,l+1,-1);
			live-=getzero(l,l+1); 
			l++;
			//printf("r:%d l:%d live:%d hlq3:%d\n",r,l,live,hl.query(3,3));
		}
		//printf("r:%d l:%d live:%d\n",r,l,live);
		chkmax(final,r-l+1);
		assert(l<=r);
	}
	printf("%d\n",final);
}