#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int mod = 1000000007;
int n;
map<int, int> p, sz, cn;
ll res = 1;

int parent (int a) {
	if (!p.count(a)) {
		p[a] = a;
		cn[a] = 1;
		return a;
	}
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	sz[a]++;
	if (a == b) return;
	sz[a] += sz[b];
	cn[a] += cn[b];
	p[b] = p[a];
}

ll pot (ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		join(2 * x, 2 * y + 1);
	}

	for (auto it = p.begin(); it != p.end(); it++)
		if (it->fi == it->se)
			(res *= pot(2, cn[it->fi]) - (sz[it->fi] < cn[it->fi])) %= mod;

	cout << MOD(res, mod) << endl;

	return 0;
}