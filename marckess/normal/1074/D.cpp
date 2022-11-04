#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int q, op, l, r, x, last = 0;
map<int, int> d, p, off;

int parent (int a) {
	if (p[a] == a) return a;
	int to = p[a];
	p[a] = parent(p[a]);
	d[a] ^= d[to];
	return p[a];
}

void joint () {
	if (!p.count(l)) p[l] = l;
	if (!p.count(r)) p[r] = r;

	int a = parent(l), b = parent(r);
	if (a == b) return;
	p[a] = b;
	d[a] = d[l] ^ d[r] ^ x;
}

int query () {
	if (!p.count(l)) return -1;
	if (!p.count(r)) return -1;

	if (parent(l) != parent(r)) return -1;
	return d[l] ^ d[r];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &q);
	while (q--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &x);
			l ^= last, r ^= last, x ^= last;
			if (l > r) swap(l, r);
			l--;

			joint();
		} else {
			scanf("%d%d", &l, &r);
			l ^= last, r ^= last;
			if (l > r) swap(l, r);
			l--;

			int d = query();
			last = abs(d);
			printf("%d\n", d);
		}
	}

	return 0;
}