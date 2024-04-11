#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n = 1, m, sig[MX][26], st[4*MX], p[MX], a[MX], u, v, ini[MX], fin[MX];
ll res = 0;
string s;
vi adj[MX];
bitset<MX> f;

void merge (int pos) {
	if (a[st[pos*2]] > a[st[pos*2+1]])
		st[pos] = st[pos*2];
	else
		st[pos] = st[pos*2+1];
}

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		st[pos] = i;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	merge(pos);
}

void update (int x, int k) {
	int pos = p[x];
	a[x] = k;
	pos /= 2;

	while (pos) {
		merge(pos);
		pos /= 2;
	}
}

int query (int i, int j, int pos, int l, int r) {
	if (r < i || j < l) return 0;
	if (l <= i && j <= r) return st[pos];

	int m = (i+j)/2;
	int x = query(i, m, pos*2, l, r);
	int y = query(m+1, j, pos*2+1, l, r);
	if (a[x] > a[y]) return x;
	return y;
}

void insert (string &s) {
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!sig[j][s[i]]) {
			sig[j][s[i]] = n++;
			adj[j].pb(n-1);
		}
		j = sig[j][s[i]];
	}
	f[j] = 1;
}

void dfs (int u, int l) {
	ini[u] = ++m;
	if (f[u]) {
		a[ini[u]] = l;
		res += l;
	}

	for (int v : adj[u])
		dfs(v, l+1);
	
	fin[u] = m;
}

void obtRes (int u, int l) {
	for (int v : adj[u])
		obtRes(v, l+1);

	if (u && !f[u]) {
		int x = query(1, m, 1, ini[u], fin[u]);
		res += l - a[x];
		update(x, l);
	}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> m;
    while (m--) {
    	cin >> s;
    	for (char &c : s) c -= 'a';
    	insert(s);
    }

    m = 0;
    dfs(0, 0);

    build(1, m, 1);
    obtRes(0, 0);

    cout << res << endl;

    return 0;
}