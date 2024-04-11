#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 210;
const int MAXM = 20100;

bool sieve[MAXM];

namespace TM{ //Turbo Matching O(nm)
	//-----------------te ustawiamy przed uzyciem------------------
	const int MAXN = 210;  //musi zmiescic c+d
	vector<int> V[MAXN];   //wystarczy tylko od chlopcow
	int c,d;               //chlopcy 0..c-1, dziewczyny: c..c+d-1
	//-----------------te sa wynikowe------------------------------
	int M[MAXN];
	//----------------te sa pomocniczne-----------------------------
	bool odw[MAXN];
	queue<int> Q;

	inline bool dfs(int u)
	{  
		odw[u]=1;
		Q.push(u);
		tr(it,V[u]) if((M[*it]==-1) || (!odw[M[*it]] && dfs(M[*it])))
		{
			M[u]=*it;
			M[*it]=u;
			return 1;
		}
		return 0;
	}
	int matching() //zwraca rozmiar matchingu
	{
		fru(i,c) odw[i]=0;
		fru(i,c+d) M[i]=-1;
		bool czy=1;
		while(czy)
		{
			for(czy=0;!Q.empty();Q.pop()) odw[Q.front()]=0;
			fru(i,c) if(M[i]==-1 && !odw[i]) czy|=dfs(i);
		}
		int ret=0;
		fru(i,c) if(M[i]!=-1) ++ret;
		return ret;
	}
}
using TM::V;
using TM::c;
using TM::d;
using TM::M;

int MM[MAXN];
vi vis;
void mdfs(vi &cyc, int u) {
	if(vis[u]) return;
	cyc.pb(u);
	vis[u]=1;
	if(u<c) return mdfs(cyc, MM[u]);
	else return mdfs(cyc, M[u]);
}

void imp() {
	puts("Impossible");
	exit(0);
}

void solve() {
	int n;
	scanf("%d",&n);
	vi X(n), renum(n);
	fru(i,n) {
		int a; scanf("%d",&a);
		if(a%2) {
			renum[i] = c++;
		} else {
			renum[i] = n-(++d);
		}
		X[renum[i]] = a;
	}
	fru(i,n) fru(j,n) if(i<j) {
		if(!sieve[X[i]+X[j]]) {
			V[i].pb(j);
			V[j].pb(i);
			assert(i<c && j>=c);
		}
	}
	if(TM::matching()*2 != c+d) imp();
	vector<vi> W(n);
	fru(i,c) tr(it, V[i]) {
		if(M[i]!=*it) {
			W[i].pb(*it);
			W[*it].pb(i);
		}
	}
	fru(i,n) swap(V[i], W[i]);
	fru(i,n) MM[i]=M[i];
	if(TM::matching()*2 != c+d) imp();
	vector<vi> ans;
	vis.resize(n);
	fru(i,n) {
		if(vis[i]) continue;
		vi cyc;
		mdfs(cyc,i);
		assert(cyc.size() > 2);
		ans.pb(cyc);
	}
	vi odw(n);
	fru(i,n) odw[renum[i]]=i;
	printf("%lu\n", ans.size());
	tr(ic, ans) {
		printf("%lu ", ic->size());
		tr(it, *ic) printf("%d ", odw[*it]+1);
		puts("");
	}
}

int main() {
	sieve[0] = sieve[1] = 1;
	for(int i=2; i*i < MAXM; i++) {
		if(!sieve[i]) for(int j=i*i; j < MAXM; j+=i) sieve[j] = 1;
	}
	//	freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	int t=1;
	//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}