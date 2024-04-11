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

const int MX = 200005;
int n, m;
ll l, r;
vi d[MX], res[MX];
set<int> st;
queue<int> in[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> l >> r;

	for (int i = 1; i < MX; i++)
		for (int j = i; j < MX; j += i) 
			d[j].pb(i);

	int x = 1, y = 1;
	for (int i = n; i; i--) {
		int a = min((l + i - 1) / i, 1ll * m + 1), b = min(r / i, 1ll * m);

		while (y <= b) {
			for (int z : d[y]) {
				in[z].push(y);

				if (in[z].size() == 1)
					st.insert(z);
			}
			y++;
		}

		while (x < a) {
			for (int z : d[x]) {
				in[z].pop();

				if (!in[z].size())
					st.erase(z);
			}
			x++;
		}

		int f = 0;

		for (int z : d[i]) {
			auto it = st.lower_bound(z + 1);

			if (it != st.end() && *it <= n / (i / z)) {
				int y = in[*it].front();

				res[i] = {i, y, i / z * *it, y / *it * z};
				
				f = 1;
				break;
			}
		}

		if (!f) res[i] = {-1};
	}

	for (int i = 1; i <= n; i++) {
		for (int r : res[i])
			cout << r << " ";
		cout << endl;
	}

	return 0;
}