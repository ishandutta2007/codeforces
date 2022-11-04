#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef vector<ll> vl;
const int MX = 250005;
const ll inf = 1e12;

struct Treap{
	Treap *left, *right;
	int val, key, size;
	ll sum;

	Treap(int val = 0): val(val), key(rand()), size(1), left(0), right(0), sum(val) { }
}*t[MX];

inline int nodeSize (Treap *T) { return T ? T->size : 0; }
inline ll nodeSum (Treap* T) { return T ? T->sum : 0; }

inline void update(Treap* T){
	if (T) {
		T->size = 1 + nodeSize(T->left) + nodeSize(T->right);
		T->sum = T->val + nodeSum(T->left) + nodeSum(T->right);
	}
}

void merge (Treap* &T, Treap* T1, Treap* T2) {
	if (!T1) T = T2;
	else if (!T2) T = T1;
	else if (T1->key > T2->key)
		merge (T1->right, T1->right, T2), T = T1;
	else
		merge (T2->left, T1, T2->left), T = T2;
	update (T);
}

void split (Treap* T, int x, Treap* &T1, Treap* &T2) {
	if (!T)
		return void(T1 = T2 = NULL);
	if (x < T->val)
		split (T->left, x, T1, T->left), T2 = T;
	else
		split (T->right, x, T->right, T2), T1 = T;
	update (T);
}

void insert(Treap* &T, Treap* x){
	if (!T) T = x;
	else if (x->key > T->key)
		split (T, x->val, x->left, x->right), T = x;
	else
		insert (x->val < T->val ? T->left : T->right, x);
	update (T);
}

void insert (Treap* &T, int x) { insert(T, new Treap(x)); }

void erase (Treap* &T, int x){
	if (!T) return;
	if (T->val == x)
		merge (T, T->left, T->right);
	else
		erase (x < T->val ? T->left : T->right, x);
	update (T);
}

ll kth (Treap *T, int i) {
	if (!T || i<1) return 0;
	int curr = nodeSize(T->left);
	if (i == curr + 1)
		return nodeSum(T->left) + T->val;
	if (i < curr + 1)
		return kth(T->left, i);
	return kth(T->right, i - curr - 1) + nodeSum(T->left) + T->val;
}

int n, a, b, c, x, vis[MX], p[MX];
ll res[MX], mem[2][MX];
vi deg[MX], in;
vii adj[MX], gra[MX];
bitset<MX> bs;

ll dp (int u, int p, int f) {
	ll &res = mem[f][u];
	if (res != -1) return res;
	res = inf;
	vis[u] = x;

	ll s = 0;
	vl aux;

	for (ii &v : gra[u])
		if (v.fi != p) {
			s += dp(v.fi, u, 0);
			aux.pb(dp(v.fi, u, 1) - dp(v.fi, u, 0) + v.se);
		}
	sort(all(aux));

	for (int k = 0; k <= aux.size(); k++) {
		int d = (int)adj[u].size() - x - f;
		if (d - k <= nodeSize(t[u]))
			res = min(res, s + kth(t[u], d - k));
		if (k < aux.size())
			s += aux[k];
	}

	return res;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	srand(time(0));

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	for (int i = 1; i <= n; i++)
		deg[adj[i].size()].pb(i);

	for (x = n - 1; x >= 0; x--) {
		for (int u : in)
			if (mem[0][u] == -1)
				res[x] += dp(u, -1, 0);

		for (int u : in)
			mem[0][u] = mem[1][u] = -1;

		for (int u : deg[x]) {
			bs[u] = 1;
			in.pb(u);
			
			for (ii &v : adj[u])
				if (bs[v.fi]) {
					erase(t[v.fi], v.se);
					gra[u].emplace_back(v.fi, v.se);
					gra[v.fi].emplace_back(u, v.se);
				} else {
					insert(t[u], v.se);
				}
		}
	}
	
	for (int i = 0; i < n; i++)
		printf("%I64d ", res[i]);
	printf("\n");

	return 0;
}