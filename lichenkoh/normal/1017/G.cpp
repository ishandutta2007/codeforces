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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1e5+4;
int inp[mn];
typedef pii STV;
typedef int STD;
class HeavyLight2NoRecursion {
public:
	// true - values on vertices, false - values on edges
	bool VALUES_ON_VERTICES = true;

  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return MP(x.fst+y,x.snd+y);
  }

  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
  	//printf("l:%d r:%d l+r:%d r:%d\n",l,r,l+r,r);
  	if (l==getNeutralValue()) return r;
  	if (r==getNeutralValue()) return l;
  	return MP(l.fst+r.fst,max(r.snd,l.snd+r.fst));
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    //if (isNeutralDelta(delta)) return getNeutralDelta();
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    return delta;
  }

  STD initNeutralDelta() {
  	return 0;
  }

  bool isNeutralDelta(STD delta) {
    return delta==0;
  }

	STV getInitValue(int vtx) {
		return MP(-1,-1);
	}

  STV getNeutralValue() {
  	return MP(INT_MIN,INT_MIN);
  }

  STD joinDeltas(STD d1, STD d2) {
    return d1+d2;
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
		initInput();
	}
	void initInput() {
		int n = (int)this->tree.size();
		for (int vtx=0;vtx<n;vtx++) {
			int path_idx=vpath[vtx];
			int m = pathSize[path_idx];
			int j=pathPos[vtx];
			dbg("vtx:%d path:%d pathpos:%d\n",vtx,path_idx,pathPos[vtx]);
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
		dbg("path:%d i:%d val:%d delta:%d\n",path,i,vvalue[path][i],deltaEffectOnSegment(vdelta[path][i], len[path][i]));
		return joinValueWithDelta(vvalue[path][i], deltaEffectOnSegment(vdelta[path][i], len[path][i]));
	}

	STV queryPath(int path, int from, int to) {
		dbg("path:%d on %d->%d \n",path,from,to);
		from += pathSize[path];
		to += pathSize[path];
		pushDelta(path, from);
		pushDelta(path, to);
    STV resl = getNeutralValue(), resr = getNeutralValue();
    bool found = false;
    for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        resl = found ? queryOperation(resl, joinValueWithDelta0(path,from)) : joinValueWithDelta0(path,from);
        found = true;
      }
      if ((to & 1) == 0) {
        resr = found ? queryOperation(joinValueWithDelta0(path, to), resr) : joinValueWithDelta0(path, to);
        found = true;
      }
    }
    STV res=queryOperation(resl,resr);
    dbg("gives %d\n",res);
    return res;
	}

	void modifyPath(int path, int from, int to, STD delta) {
		dbg("modify path:%d on %d->%d with %d\n",path,from,to,delta);
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
    for (int i = ta; i > 1; i >>= 1) {
      int k=i>>1;
      vvalue[path][k] = queryOperation(joinValueWithDelta0(path, k<<1), joinValueWithDelta0(path, (k<<1)|1));
    }
    for (int i = tb; i > 1; i >>= 1) {
      int k=i>>1;
      vvalue[path][k] = queryOperation(joinValueWithDelta0(path, k<<1), joinValueWithDelta0(path, (k<<1)|1));
    }
	}

	bool isAncestor(int p, int ch) {
		return tin[p] <= tin[ch] && tout[ch] <= tout[p];
	}

	STV query(int a, int b) {
		dbg("Query: %d %d\n",a,b);
		STV res = getNeutralValue();
		for (int root; !isAncestor(root = pathRoot[vpath[a]], b); a = parent[root])
			res = queryOperation(res, queryPath(vpath[a], 0, pathPos[a]));
		for (int root; !isAncestor(root = pathRoot[vpath[b]], a); b = parent[root])
			res = queryOperation(queryPath(vpath[b], 0, pathPos[b]), res);
		if (!VALUES_ON_VERTICES && a == b)
			return res;
		return queryOperation(
			queryPath(vpath[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
					max(pathPos[a], pathPos[b])),
			res
		);
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
vvi g;
vi v2q[mn];
pii q2tv[mn];
vi q2undo[mn];
pii q2op[mn];
set<int> s;
void dfs(int v, int p) {
	for (auto &q:v2q[v]) {
		if (q2tv[q].fst==3) continue;
		auto it=s.lower_bound(q);
		if (it!=s.end()) {
			q2undo[*it].PB(q);
		}
		if (q2tv[q].fst==2) s.insert(q);
	}
	for (auto &y:g[v]) {
		if (y!=p) dfs(y,v);
	}
	for (auto &q:v2q[v]) if (q2tv[q].fst==2) s.erase(q);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //STV tmp=hl.queryOperation(MP(1,2),hl.queryOperation(MP(-1,0),MP(-1,0)));
  //printf("%d %d\n",tmp.fst,tmp.snd); return 0;
  int n=rint(); int qn=rint(); g.resize(n);
  for (int i=2;i<=n;i++) {
  	int x=i; int y=rint(); --x; --y;
  	g[x].PB(y); g[y].PB(x);
  }
  for (int qi=0;qi<qn;qi++) {
  	int t=rint(); int v=rint()-1;
  	q2tv[qi]=MP(t,v);
  	v2q[v].PB(qi);
  }
  dfs(0,-1);
  for (int x=0;x<qn;x++) sort(q2undo[x].begin(),q2undo[x].end());
  hl.init(g);
	for (int q=0;q<qn;q++) {
		int t=q2tv[q].fst,v=q2tv[q].snd;
		if (t==1) {
			q2op[q]=(MP(v,1));
			hl.modify(v,v,1);
		}
		else if (t==2) {
			for (auto &u:q2undo[q]) {
				auto w=q2op[u];
				if (w.snd!=0) {
					hl.modify(w.fst,w.fst,-w.snd);
				}
			}
			STV got=hl.query(0,v);
			int plus=got.snd-(-1);
			if (plus>0) {
				q2op[q]=(MP(v,-plus));
				hl.modify(v,v,-plus);
			}
		}
		else {
			STV got=hl.query(0,v);
			//printf("v:%d got:%d %d\n",v,got.fst,got.snd);
			if(got.snd>=0) printf("black\n");
			else printf("white\n");
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