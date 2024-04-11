#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, NH = 2;
int n, u, v, b[NH], mod[NH] = {int(1e9+21), int(1e9+9)}, r;
vi adj[MX];

ll h[MX][NH];
int uni = 0, mx = 0, ind = 1;
map<ll, int> mp;

void pre () {
	for (int i = 0; i < NH; i++)
		b[i] = abs(rand() % (mod[i] - 2)) + 2;
}

ll pot (ll b, int p, int mod) {
	ll res = 1;
	b %= mod;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

void insert (ll g) {
	if (!mp[g]) uni++;
	mp[g]++;
}

void erase (ll g) {
	mp[g]--;
	if (!mp[g]) uni--;
}

void dfs (int u, int p) {
	for (int i = 0; i < NH; i++) h[u][i] = (b[i] + int(1e9+7)) % mod[i];

 	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			for (int i = 0; i < NH; i++) {
				h[u][i] *= b[i] + h[v][i];
				h[u][i] %= mod[i];
			}
		}

	insert(h[u][0] * mod[1] + h[u][1]);
}

void obtRes (int u, int p) {
	ll t[NH], aux[NH];

	for (int i = 0; i < NH; i++) aux[i] = h[u][i];
	erase(aux[0] * mod[1] + aux[1]);
	
	if (u != r) {
		insert(h[p][0] * mod[1] + h[p][1]);
		for (int i = 0; i < NH; i++) {
			h[u][i] *= b[i] + h[p][i];
			h[u][i] %= mod[i];
		}
	}
	
	for (int i = 0; i < NH; i++) t[i] = h[u][i];
	insert(t[0] * mod[1] + t[1]);

	if (uni > mx) {
		mx = uni;
		ind = u;
	}

	erase(t[0] * mod[1] + t[1]);

	for (int v : adj[u]) {
		if (v == p) continue;
		for (int i = 0; i < NH; i++)
			h[u][i] = t[i] * pot(b[i] + h[v][i], mod[i]-2, mod[i]) % mod[i];
		obtRes(v, u);
	}

	if (u != r) erase(h[p][0] * mod[1] + h[p][1]);
	insert(aux[0] * mod[1] + aux[1]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	pre();

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	r = (rand()%n)+1;
	dfs(r, r);
	obtRes(r, r);

	cout << ind << endl;

	return 0;
}