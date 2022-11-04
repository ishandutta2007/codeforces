
// Problem : F. Interesting Sections
// Contest : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1609/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node *l, *r;
	int x, y, sz;
	
	Node (int x) : 
		l(0), 
		r(0), 
		x(x), 
		y(uniform_int_distribution<int>(-2e9, 2e9)(rng)), 
		sz(1) {}
};

int size (Node *t) {
	return t ? t->sz : 0;
}

void update (Node *t) {
	if (t) t->sz = size(t->l) + 1 + size(t->r);
}

void split (Node *t, Node *&l, Node *&r, int x) {
	if (!t) {
		l = r = 0;
		return;
	}

	if (x <= t->x)
		split(t->l, l, t->l, x), r = t;
	else
		split(t->r, t->r, r, x), l = t;

	update(t);
}

Node *merge (Node *l, Node *r) {
	if (!l)
		return r;

	if (!r)
		return l;

	if (l->y > r->y) {
		l->r = merge(l->r, r);
		update(l);
		return l;
	}
	
	r->l = merge(l, r->l);
	update(r);
	return r;
}

int n, b[MX];
stack<ii> mx, mn;
ll a[MX], acu, res;
Node *tmn[64], *tmx[64];

vector<Node*> split (Node *t, int a, int b) {
	vector<Node*> v(3);
	split(t, v[0], v[1], a);
	split(v[1], v[1], v[2], b + 1);
	return v;
}

Node *merge (vector<Node*> v) {
	for (int i = 1; i < (int)v.size(); i++)
		v[0] = merge(v[0], v[i]);
	return v[0];
}

void update (int i, stack<ii> &st, Node *ta[64], Node *tb[64], function<bool(ll, ll)> fun) {
	Node *aux = 0;
	
	while (st.size() && fun(st.top().fi, a[i])) {
		int r = st.top().se;
		st.pop();
		int l = st.size() ? st.top().se + 1 : 0;
		
		auto va = split(ta[b[r]], l, r);
		auto vb = split(tb[b[r]], l, r);
		
		acu -= size(va[1]);
		
		ta[b[r]] = merge(va);
		tb[b[r]] = vb[0], aux = merge(vb[1], aux);
	}
	
	ta[b[i]] = merge(ta[b[i]], new Node(i));
	
	int r = i;
	int l = st.size() ? st.top().se + 1 : 0;
	
	auto va = split(ta[b[r]], l, r);
	acu += size(va[1]);
	ta[b[r]] = merge(va);
	
	aux = merge(aux, new Node(i));
	tb[b[r]] = merge(tb[b[r]], aux);
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	forn (i, n) {
		b[i] = __builtin_popcountll(a[i]);
		
		if (!i || a[i - 1] <= a[i])
			update(i, mx, tmn, tmx, [] (ll x, ll y) { return x <= y; });
		else
			update(i, mn, tmx, tmn, [] (ll x, ll y) { return x >= y; });
		
		mn.emplace(a[i], i);
		mx.emplace(a[i], i);
		
		res += acu;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}