#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned int ui;
typedef pair <int, ll> PIL;
typedef pair <int, int> PII;
#define maxn 100100
const ll INF = 1e13;
int n, m, a, b, c, mod;
bool gold[maxn], odw[maxn];
int tp[maxn], r[maxn], maks[maxn], DL = 0, d[maxn];
bool ans[maxn], mean[maxn];
vector <PII> v[maxn];
int nowe[maxn], TP = 0;
ll pot[maxn], inv[maxn];
ll wDol[maxn], wGore[maxn], wyn;

inline ll potmod(ll a, ll b, ll MOD) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a )% MOD;
	}
	return res;
}

map <ll, ll> M;
void liczdfs(int x) {
	odw[x] = 1;
	tp[++DL] = x;
	r[x] = 1;
	for (ui i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i].e1] && !gold[v[x][i].e1]) {
		  liczdfs(v[x][i].e1);
		  r[x] += r[v[x][i].e1];
		  maks[x] = max(maks[x], r[v[x][i].e1]);
	  }
}

void countdfs(int x, ll valuewGore, ll valuewDol) {
	if (gold[x]) return;
	odw[x] = 1;
	wDol[x] = valuewDol;
	wGore[x] = valuewGore;
	ll g = (mod - wGore[x] + mod) % mod;
	ll szukaj = g * inv[d[x]] % mod;
	wyn += M[szukaj];
	
	nowe[++TP] = x;
	for (ui i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i].e1] && !gold[v[x][i].e1]) {
		  d[v[x][i].e1] = d[x] + 1;
		  countdfs(v[x][i].e1, (valuewGore * 10 + v[x][i].e2)%mod, (valuewDol + v[x][i].e2 * pot[d[x]])%mod);
	  }
}

void Simulate(int x) {
	if(gold[x]) return;
	
	M.clear();
	
	int CTR = 0;
	liczdfs(x);
	int N = DL, POL = (DL / 2);
	for (int i=1; i<=DL; ++i) {
		int u = tp[i];
		maks[u] = max(maks[u], N - r[u]);
		if (maks[u] <= POL) CTR = u;
		r[u] = 0, odw[u] = 0, maks[u] = 0, wGore[u] = 0, wDol[u] = 0;
	}

	gold[CTR] = 1;

	for (ui i=0; i<v[CTR].size(); ++i)
	  if (!gold[v[CTR][i].e1]) {
		  d[v[CTR][i].e1] = 1;
		  TP = 0;
		  countdfs(v[CTR][i].e1, v[CTR][i].e2 % mod, v[CTR][i].e2 % mod);
		  FOR(el, 1, TP) M[wDol[nowe[el]]]++;
	}
	
	for (int i=1; i<=DL; ++i) {
		odw[tp[i]] = 0, wDol[tp[i]] = wGore[tp[i]] = 0;
	}
	
	M.clear();
	for (int i=v[CTR].size()-1; i>=0; --i)
	if (!gold[v[CTR][i].e1]) {
		d[v[CTR][i].e1] = 1;
		  TP = 0;
		  countdfs(v[CTR][i].e1, v[CTR][i].e2 % mod, v[CTR][i].e2 % mod);
		  FOR(el, 1, TP) M[wDol[nowe[el]]]++;
	}
	
	for (int i=1; i<=DL; ++i) {
		if (wDol[tp[i]] == 0 && tp[i] != CTR) ++wyn;
		if (wGore[tp[i]] == 0 && tp[i] != CTR) ++wyn;
		odw[tp[i]] = 0, d[tp[i]] = 0;
	}

	DL = 0;
	M.clear();

	for (ui i=0; i<v[CTR].size(); ++i) {
	  if (!gold[v[CTR][i].e1]) Simulate(v[CTR][i].e1);
  }

}

inline bool isprime(int x) {
	for (int i=2; i*i<=x; ++i)
	  if (x % i == 0) return 0;
	return 1;
}

int main() {
	boost;
	cin >> n >> mod;
	if (mod == 1) {
		ll en = n;
		cout << en * (en - 1);
		exit(0);
	}
	ll PHI = mod - 1;
	if (isprime(mod));
	else {
		int mmm = mod;
		PHI = mod;
		for (int i=2; i*i<=mod; ++i)
		  if (mmm % i == 0 && isprime(i)) {
			  PHI = (PHI * (i-1) )/i;
			  while (mmm % i == 0) mmm /= i;
		  }
		if (mmm > 1 && isprime(mmm)) PHI = PHI * (mmm-1)/mmm;
	}
	
	//if (mod == 27) cout << PHI << endl;
	pot[0] = 1;
	FOR(i, 1, n) pot[i] = (pot[i-1] * 10) % mod;
	FOR(i, 0, n) inv[i] = potmod(pot[i], PHI - 1, mod);
	
	FOR(i, 2, n) {
		cin >> a >> b >> c;
		++a; ++b;
		v[a].pb({b, c});
		v[b].pb({a, c});
	}
	
	Simulate(1);
	cout << wyn;
}