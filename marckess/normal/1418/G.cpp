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

const int MX = 500005;
int n, a[MX], ptr[MX];
int cn[4 * MX], st[4 * MX];
ll res;
vi pos[MX];
stack<ii> ant[MX];

void update (int i, int j, int pos, int a, int b, int k) {
	if (j < a || b < i) return;

	if (a <= i && j <= b) {
		cn[pos] += k;

		if (cn[pos]) {
			st[pos] = (j - i + 1);
		} else if (i < j) {
			st[pos] = st[pos * 2] + st[pos * 2 + 1];
		} else {
			st[pos] = 0;
		}

		return;
	}

	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);

	if (!cn[pos]) 
		st[pos] = st[pos * 2] + st[pos * 2 + 1];
}

void insert (int a, int b, int k) {
	ant[k].emplace(a, b);
	update(1, n, 1, a, b, 1);
}

void insert (int i, int k) {
	if (i == pos[k].size()) return;

	if (i + 2 < pos[k].size())
		insert(pos[k][i], pos[k][i + 2] - 1, k);
	else
		insert(pos[k][i], n, k);

	if (i + 3 < pos[k].size())
		insert(pos[k][i + 3], n, k);
}

void clear (int k) {
	while (ant[k].size()) {
		int a = ant[k].top().fi;
		int b = ant[k].top().se;
		ant[k].pop();
		update(1, n, 1, a, b, -1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}

	for (int i = 1; i <= n; i++)
		insert(0, i);

	for (int i = 1; i <= n; i++) {
		res += n - st[1];

		clear(a[i]);
		update(1, n, 1, i, i, MX);

		ptr[a[i]]++;
		insert(ptr[a[i]], a[i]);
	}

	cout << res << endl;

	return 0;
}