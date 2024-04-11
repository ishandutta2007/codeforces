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

struct Node {
	Node *sig[2];
	vi x;
	
	Node () {
		memset(sig, 0, sizeof(sig));
	}
};

const int MX = 300005;
int n, k, a[MX];
Node *trie;

void insert (int a, int ind) {
	Node *t = trie;
	
	for (int j = 30; j >= 0; j--) {
		int c = bool(a & (1 << j));
		
		if (!t->sig[c])
			t->sig[c] = new Node();
		t = t->sig[c];
	}
	
	t->x.pb(ind);
}

vi dfs (Node *t, Node *u, int j, int f) {
	if (!t) swap(t, u);
	if (!t) return {};
	
	if (j == -1) {
		vi res;
		if (t) res.pb(t->x[0]);
		if (u) res.pb(u->x[0]);
		return res;
	}
	
	vi x, y;
	
	if (!u) {
		x = dfs(t->sig[0], 0, j - 1, f);
		y = dfs(t->sig[1], 0, j - 1, f);
		
	} else if (f) {
		x = dfs(t->sig[0] ? t->sig[0] : t->sig[1], u->sig[0] ? u->sig[0] : u->sig[1], j - 1, 1);
		
	} else if (k & (1 << j)) {
		x = dfs(t->sig[0], u->sig[1], j - 1, 0);
		y = dfs(t->sig[1], u->sig[0], j - 1, 0);
		
	} else if (t->sig[0] && u->sig[1]) {
		x = dfs(t->sig[0], u->sig[1], j - 1, 1);
		
	} else if (t->sig[1] && u->sig[0]) {
		x = dfs(t->sig[1], u->sig[0], j - 1, 1);
		
	} else {
		x = dfs(t->sig[0], u->sig[0], j - 1, 0);
		y = dfs(t->sig[1], u->sig[1], j - 1, 0);
	}
	
	if (x.size() < y.size())
		swap(x, y);
	return x;
}

vi res;
void dfs (Node *t, int j) {
	if (!t) return;
	
	if (j == -1) {
		for (int x : t->x)
			res.pb(x);
		return;
	}
	
	if (k & (1 << j)) {
		vi x = dfs(t->sig[0], t->sig[1], j - 1, 0);
		for (int k : x)
			res.pb(k);
		return;
	}
	
	dfs(t->sig[0], j - 1);
	dfs(t->sig[1], j - 1);
}

void main_() {
	cin >> n >> k;
	
	trie = new Node();
	forn (i, n) {
		cin >> a[i];
		insert(a[i], i);
	}
	
	dfs(trie, 30);
	
	if (res.size() < 2) {
		cout << -1 << endl;
		return;
	}
	
	cout << res.size() << endl;
	for (int x : res)
		cout << x + 1 << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}