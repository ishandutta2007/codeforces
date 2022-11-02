#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<char> vc;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

int n;
vector<vector<pii>> V;
vc S;
map<pii,pli> MEM;

struct cmp {
	bool operator()(pair<pii,pli> a, pair<pii,pli> b) const {
		if(a.y != b.y) return a.y > b.y;
		return a.x < b.x;
	}
};

pli dfs(int u, int par) {
	{
		auto it = MEM.find(pii(u,par));
		if(it != MEM.end()) return it->y;
	}
	pli ret = pli(S[u] ? 0 : -inft, -1);
	pii jaki = pii(-1,-1);
	for(pii e : V[u]) if(e.x != par) {
		pli ww = dfs(e.x, u);
		ww.x += e.y;
		if(ww.x == ret.x) {
			jaki = pii(ret.y, e.x);
			ret.y = -1;
		}
		else if(ww.x > ret.x) ret = pli(ww.x, e.x);
	}
	if(par == -1) {
		// przyspieszacz
		if(jaki.x == -1) jaki.y = -1;
		for(pii e : V[u]) {
			pli ww = dfs(e.x, u);
			ww.x += e.y;
			if(ww.x == ret.x) {
				if(ret.y != -1) dfs(u, e.x); // liczymy osobno
				else if(e.x == jaki.x || e.x == jaki.y)
					MEM[pii(u,e.x)] = pii(ret.x, e.x^jaki.x^jaki.y);
				else MEM[pii(u,e.x)] = ret;
			} else MEM[pii(u,e.x)] = ret;
		}
	}
	return MEM[pii(u,par)] = ret;
}

void wave(int u, int par) {
	dfs(u,-1);
	for(pii e : V[u]) if(e.x != par) wave(e.x, u);
}

void solve() {
	int k;
	scanf("%d%d",&n,&k);
	vi P; V.resize(n); S.resize(n);
	fru(j,k) {
		int x;
		scanf("%d",&x);
		x--;
		P.pb(x);
		S[x]=1;
	}
	fru(j,n-1) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--; b--;
		V[a].pb(pii(b,c));
		V[b].pb(pii(a,c));
	}
	wave(0,-1);
//	for(pair<pii,pli> m : MEM) printf("[%d,%d] -> %lld / %d\n",m.x.x+1,m.x.y+1,m.y.x,m.y.y+1);
	map<pair<pii,pli>,int,cmp> M; // (u, par) -> ile
	vi ANS(n);
	for(int x : P) M[make_pair(pii(x,-1),MEM[pii(x,-1)])]++;
	while(!M.empty()) {
		pii e = M.begin()->x.x;
		int next = M.begin()->x.y.y;
		ll ile = M.begin()->y;
		M.erase(M.begin());
		ANS[e.x] += ile;
		if(next != -1) M[make_pair(pii(next,e.x),MEM[pii(next,e.x)])] += ile;
	}
	pii best = pii(-1,-1);
	fru(i,n) if(!S[i]) {
		if(ANS[i] > best.x) best = pii(ANS[i],0);
		if(ANS[i] == best.x) best.y++;
	}
	printf("%d %d\n", best.x, best.y);
	V.clear(); S.clear(); MEM.clear();
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}