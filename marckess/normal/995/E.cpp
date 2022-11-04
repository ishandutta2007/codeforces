#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MP = 100000, maxi = 200000010;

bitset<maxi> bs;
int p[MP][100], u, v, mod, inv[100];
vi res;

int pot (ll b, int p) {
	ll res = 1;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p >>= 1;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	cin >> u >> v >> mod;

	for (int i = 0; i < MP; i++) {
		int act = u;
		for (int j = 0; j < 100; j++) {
			int d = p[i][j] = rand() % 3 + 1;
			
			if (d == 1) act = (act + 1) % mod;
			else if (d == 2) act = (act + mod - 1) % mod;
			else act = pot(act, mod-2);

			if (act < maxi)
				bs[act] = 1;
		}
	}

	bool f = 1;
	while (f) {
		int act = v;

		for (int i = 0; i < 100; i++) {
			int d = inv[i] = rand() % 3 + 1;

			if (d == 1) act = (act + mod - 1) % mod;
			else if (d == 2) act = (act + 1) % mod;
			else act = pot(act, mod-2);

			if (act < maxi && bs[act]) {
				for (int j = 0; j < MP; j++) {
					int aux = u;

					for (int k = 0; k < 100; k++) {
						
						if (p[j][k] == 1) aux = (aux + 1) % mod;
						else if (p[j][k] == 2) aux = (aux + mod - 1) % mod;
						else aux = pot(aux, mod-2);

						if (aux == act) {
							for (int l = 0; l <= k; l++)
								res.push_back(p[j][l]);
							
							for (int l = i; l >= 0; l--)
								res.push_back(inv[l]);
							
							f = 0;
							break;
						}
					}

					if (!f) break;
				}

				break;
			}
		}
	}

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}