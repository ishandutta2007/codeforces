#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

class HeavyLight2NoRecursion {

	// true - values on vertices, false - values on edges
	bool VALUES_ON_VERTICES = true;

	// Modify the following 6 methods to implement your custom operations on the tree.
	// This example implements Add/Max operations. Operations like Add/Sum, Set/Max can also be implemented.
	int modifyOperation(int x, int y) {
		return x + y;
	}

	// query (or combine) operation
	int queryOperation(int leftValue, int rightValue) {
		return leftValue + rightValue;
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



const ll mn=2e5+4;
ll n;
vector<pll> g[mn];
vector<pll> v;
ll a[mn];
vector<pll> queries;
void dfs(ll x) {
	ll vsz=v.size();
	ll depth;
	//printf("x:%lld. ",x);
	//for (auto &w:v) printf("(%lld,%lld) ",w.first,w.second);
	//printf("\n");
	depth=v[vsz-1].second;
	ll imin=0,imax=vsz;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		if (v[imid].second<depth-a[x]) imin=imid+1;
		else imax=imid;
	}
	if (vsz>=2&&imin<=vsz-2) {
		ll upper=v[imin].first;
		ll p=v[vsz-2].first;
		queries.PB(MP(upper,p));
	}
	for (auto &w:g[x]) {
		ll y=w.first, e=w.second;
		v.PB(MP(y,depth+e));
		dfs(y);
		v.pop_back();
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld",a+i);
	vector<vector<int> > tree;
	tree.resize(n);
	for (ll x=2;x<=n;x++) {
		ll p,w; scanf("%lld%lld",&p,&w);
		g[p-1].PB(MP(x-1,w));
		tree[p-1].PB(x-1);
		tree[x-1].PB(p-1);
	}
	v.PB(MP(0,0));
	dfs(0);
	HeavyLight2NoRecursion hl = HeavyLight2NoRecursion(tree);
	for (auto &w: queries) {
		ll x=w.first,y=w.second;
		hl.modify(x,y,1);
	}
	for (ll x=0;x<n;x++) {
		ll lans=hl.query(x,x);
		printf("%lld ",lans);
	}
	printf("\n");
}