#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, u, e[MX];
ld res = -1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(15);

	cin >> n >> u;
	for (int i = 0; i < n; i++)
		cin >> e[i];

	int i = 0, k = 0;
	while (i < n) {
		while (k < n && e[k] <= e[i] + u) k++;
		k--;

		if (k >= i + 2)
			res = max(res, ld(e[k] - e[i+1]) / (e[k] - e[i]));
		i++;
	}

	if (res < 0) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}