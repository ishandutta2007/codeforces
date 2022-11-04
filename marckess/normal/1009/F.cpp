#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, x, y, res[MX], lvl[MX], ml = 0;
vi adj[MX];

struct st {
	vi v;
	int ind;
	int ml;
};

void obtl (int u, int p, int l) {
	lvl[u] = l;
	ml = max(ml, l);

	for (int v : adj[u])
		if (v != p)
			obtl(v, u, l+1);
}

st* dfs (int u, int p) {
	st *s = 0;

	for (int v : adj[u]) {
		if (v != p) {
			st *t = dfs(v, u);

			if (!s) {
				s = t;
				s->v[lvl[u]]++;

				if (s->v[lvl[u]] >= s->v[s->ind])
					s->ind = lvl[u];
			} else {
				if (s->ml < t->ml)
					swap(s, t);

				for (int i = t->ml; i >= lvl[u]; i--) {
					s->v[i] += t->v[i];
					if (s->v[i] >= s->v[s->ind])
						s->ind = i;
				}

				delete t;
			}
		}
	}

	if (!s) {
		s = new st;
		s->v.resize(lvl[u]+1);
		s->v[lvl[u]] = 1;
		s->ind = lvl[u];
		s->ml = lvl[u];
	}

	res[u] = s->ind - lvl[u];

	return s;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	obtl(1, 1, 0);
	dfs(1, 1);

	for (int i = 1; i <= n; i++)
		printf("%d\n", res[i]);

	return 0;
}