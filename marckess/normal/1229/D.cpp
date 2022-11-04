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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, k, ant[125], adj[125][125], x[1000005], fac[] = {1, 1, 2, 6, 24, 120};
map<vi, int> mp;
set<int> st;
ll res;
vi p[125];

void go (vi &a, vi &b) {
	vi aux(k);
	for (int i = 0; i < k; i++)
		aux[i] = a[b[i]-1];
	a = aux;
}

void pre () {
	vi v(k);
	iota(all(v), 1);
	
	int i = 0;
	do p[i] = v, mp[v] = i++;
	while (next_permutation(all(v)));

	for (int x = 0; x < i; x++)
		for (int y = 0; y < i; y++) {
			vi a = p[x];
			vi b = p[y];
			go(a, b);
			adj[x][y] = mp[a];
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	pre();

	for (int i = 1; i <= n; i++) {
		vi a(k);
		for (int &in : a)
			cin >> in;
		x[i] = mp[a];
	}

	for (int i = n; i > 0; i--) {
		vi v;

		st.erase(ant[x[i]]);
		ant[x[i]] = i;
		st.insert(i);

		bitset<125> bs(1);

		int f = i;
		for (int j : st) {
			res += bs.count() * (j - f);
			f = j;

			if (bs[x[j]])
				continue;
			v.pb(x[j]);

			queue<int> q;
			for (int l = 0; l < fac[k]; l++)
				if (bs[l]) {
					if (!bs[adj[l][x[j]]]) {
						bs[adj[l][x[j]]] = 1;
						q.push(adj[l][x[j]]);
					}
				}

			while (q.size()) {
				int y = q.front();
				q.pop();

				for (int z : v) {
					if (!bs[adj[y][z]]) {
						bs[adj[y][z]] = 1;
						q.push(adj[y][z]);
					}
				}
			}
		}

		res += bs.count() * (n - f + 1);
	}

	cout << res << endl;

	return 0;
}