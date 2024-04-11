// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 150005, mod = 998244353;
int n, a[MX], x, sz = 0;
ll pot[MX];

struct Node {
	int cn;
	Node *sig[2];
	int id;
	
	Node () {
		cn = 0;
		memset(sig, 0, sizeof(sig));
		id = sz++;
	}
}*trie;

int size (Node *t) {
	return t ? t->cn : 0;
}

void insert (int a) {
	Node *t = trie;
	t->cn++;
	
	for (int i = 30; i >= 0; i--) {
		int c = bool(a & (1 << i));
		
		if (!t->sig[c])
			t->sig[c] = new Node();
		t = t->sig[c];
		
		t->cn++;
	}
}

map<ii, ll> mem;
ll dfs (Node *t, Node *u, int i) {
	if (!t || !u) return 0;
	if (i < 0) return (pot[size(t)] - 1) * (pot[size(u)] - 1) % mod;
	
	if (mem.count({t->id, u->id}))
		return mem[{t->id, u->id}];
	
	ll &res = mem[{t->id, u->id}];
	
	if (!(x & (1 << i)))
		return res = (dfs(t->sig[0], u->sig[0], i - 1) + dfs(t->sig[1], u->sig[1], i - 1)) % mod;
	
	ll ct[2] = {pot[size(t->sig[0])], pot[size(t->sig[1])]};
	ll cu[2] = {pot[size(u->sig[0])], pot[size(u->sig[1])]};
	
	res = dfs(t->sig[0], u->sig[1], i - 1) * dfs(t->sig[1], u->sig[0], i - 1);
	(res += dfs(t->sig[0], u->sig[1], i - 1) * (ct[1] + cu[0] - 1)) %= mod;
	(res += dfs(t->sig[1], u->sig[0], i - 1) * (ct[0] + cu[1] - 1)) %= mod;
	(res += (ct[0] - 1) * (cu[0] - 1)) %= mod;
	(res += (ct[1] - 1) * (cu[1] - 1)) %= mod;
	
	return res;
}

ll dfs (Node *t, int i) {
	if (!t) return 0;
	if (i < 0) return pot[size(t)] - 1;
	
	if (!(x & (1 << i)))
		return (dfs(t->sig[0], i - 1) + dfs(t->sig[1], i - 1)) % mod;
	
	ll res = (pot[size(t->sig[0])] - 1) + (pot[size(t->sig[1])] - 1);
	(res += dfs(t->sig[0], t->sig[1], i - 1)) %= mod;
	
	return res;
}

void main_() {
	trie = new Node();
	
	cin >> n >> x;
	forn (i, n) {
		cin >> a[i];
		insert(a[i]);
	}
	
	cout << MOD(dfs(trie, 30), mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	pot[0] = 1;
	for (int i = 1; i < MX; i++)
		pot[i] = 2 * pot[i - 1] % mod;
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}