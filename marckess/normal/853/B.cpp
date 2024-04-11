#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct N {
	int d, a, b, c;

	bool operator < (const N ot) const {
		return c > ot.c;
	}
};

int n, m, k;
N v[100005];
priority_queue<N> pq[100005];
bitset<1000005> pos;
ll mn[1000005];

void salida () {
	ll acu = 0;
	int c = 0, j = 1;

	for (int i = 1; i <= n; i++) {
		if (pq[i].size()) {
			acu += pq[i].top().c;
			c++;
		}
	}

	for (int i = 0; i < m; i++) {
		if (v[i].b) {
			priority_queue<N> &q = pq[v[i].b];

			while (j <= v[i].d - k) {
				mn[j] = acu;
				pos[j] = c == n;
				j++;
			}

			while (q.size() && q.top().d <= v[i].d) {
				acu -= q.top().c;
				q.pop();

				if (q.size()) {
					acu += q.top().c;
				} else {
					c--;
				}
			}
		}
	}
}

ll entrada () {
	ll acu = 0;
	int cit[100005];
	int c = 0, j = 0;
	fill(cit+1, cit+1+n, 1e9);

	for (int i = 0; i < m; i++) {
		if (v[i].a) {
			while (j <= v[i].d) {
				mn[j] += acu;
				pos[j] = pos[j] && (c == n);
				j++;
			}

			if (cit[v[i].a] == 1e9) {
				cit[v[i].a] = v[i].c;
				c++;
				acu += v[i].c;
			}
			acu -= cit[v[i].a];
			cit[v[i].a] = min(cit[v[i].a], v[i].c);
			acu += cit[v[i].a];
		}
	}

	while (j < 1e6) {
		mn[j] += acu;
		pos[j] = pos[j] && (c == n);
		j++;
	}

	ll res = 1e18;
	for (int i = 1; i <= 1e6; i++)
		if (pos[i])
			res = min(res, mn[i]);

	return res == 1e18 ? -1 : res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> v[i].d >> v[i].a >> v[i].b >> v[i].c;
		
		if (v[i].b)
			pq[v[i].b].push(v[i]);
	}
	sort (v, v+m, [&] (N a, N b) {
		return a.d < b.d;
	});

	salida();
	cout << entrada() << endl;

	return 0;
}