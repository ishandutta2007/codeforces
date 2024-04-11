#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
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
typedef vector<int> vi;

const int mod1 = 1000000009;
const int mod2 = 1000000123;
const int MAXN = 300005;

typedef pii ht;
ht hashp(ht a, char c) {
	ht ret;
	ret.x = (1LL*a.x*36757 + c)%mod1;
	ret.y = (1LL*a.y*432647 + c)%mod2;
	return ret;
}

int C[MAXN];
char S[MAXN];
vector<vi> V;
vector<set<ht> > H;

void dfs(int u, int par, ht cur) {
//	printf("dfs %d %d\n",u,par);
	cur = hashp(cur,S[u]);
	H[u].insert(cur);
	tr(it,V[u]) if(*it != par) {
		dfs(*it,u,cur);
		if(H[u].size() < H[*it].size()) swap(H[u], H[*it]);
		tr(it2,H[*it]) H[u].insert(*it2);
		H[*it].clear();
	}
	C[u] += H[u].size();
}

void solve() {
	int n;
	scanf("%d",&n);
	fru(i,n) scanf("%d",&C[i]);
	scanf("%s",S);
	V.resize(n); H.resize(n);
	fru(i,n-1) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		V[a].pb(b);
		V[b].pb(a);
	}
	dfs(0,-1,ht(0,0));
//	fru(i,n) printf("%d ",C[i]); puts("");
	int best = -1, nbest = 0;
	fru(i,n) {
		if(C[i]>best) {
			best = C[i];
			nbest = 0;
		}
		if(C[i]==best) nbest++;
	}
	printf("%d\n%d\n",best,nbest);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}