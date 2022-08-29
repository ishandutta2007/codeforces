#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;

int par[100123][23], h[100123];
vector<pii> w[nax];

void jebaj(int a) {
	// par[a][0] - parent
	for(int i = 0; par[a][i] > 0; ++i)
		par[a][i+1] = par[ par[a][i] ][i];
	for(pii & e : w[a])
		if(e.st != par[a][0]) {
			par[e.st][0] = a;
			h[e.st] = h[a] + 1;
			jebaj(e.st);
		}
}
int lca(int a, int b) {
	if(h[a] < h[b]) swap(a, b);
	// we must decrease h[a]
	for(int i = 19; i >= 0; --i)
		if(h[a]-(1<<i) >= h[b])
			a = par[a][i];
	assert(h[a] == h[b]);
	for(int i = 19; i >= 0; --i)
		if(par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	if(a != b) {
		a = par[a][0];
		b = par[b][0];
	}
	assert(a == b);
	return a;
}

int two[nax];
int in[nax], out[nax], reduce[nax];
ll res;

void minusuj(int a, int b) {
	a = lca(a, b);
	//printf("%d\n", a);
	reduce[a]++;
}

void dfs(int a) {
	int toPar = -1;
	for(pii e : w[a]) {
		if(e.st == par[a][0])
			toPar = e.nd;
		else {
			dfs(e.st);
			in[a] += in[e.st];
			out[a] += out[e.st];
		}
	}
	in[a] -= reduce[a];
	out[a] -= reduce[a];
	if(toPar == 0)
		res = (res + two[out[a]]-1 + mod) % mod;
	if(toPar == 1)
		res = (res + two[in[a]]-1 + mod) % mod;
	//printf("%d - %d %d  rodz=%d\n", a, in[a], out[a], toPar);
}

int k[nax];

int main() {
	two[0] = 1;
	RI(i, nax-1) two[i] = two[i-1] * 2 % mod;
	int n;
	scanf("%d", &n);
	REP(_, n - 1) {
		int a, b, c;
		a = _ + 1;
		b = _ + 2;
		c = 0;
		scanf("%d%d%d", &a, &b, &c);
		w[a].pb(mp(b, c == 0 ? 2 : 1));
		w[b].pb(mp(a, c == 0 ? 2 : 0));
	}
	jebaj(1);
	int K;
	scanf("%d", &K);
	K++;
	k[1] = 1;
	FOR(i, 2, K) scanf("%d", &k[i]);
	RI(i, K) {
		if(i != 1 && k[i-1] != k[i]) in[k[i]]++;
		if(i != K && k[i+1] != k[i]) out[k[i]]++;
	}
	RI(i, K-1) if(k[i] != k[i+1]) if(k[i] != k[i+1]) minusuj(k[i], k[i+1]);
	dfs(1);
	printf("%lld\n", res);
	return 0;
}