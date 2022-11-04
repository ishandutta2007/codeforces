#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vii res;
	vi dist(n+2);

	for (int i = 1; i <= k; i++) {
		int act = i;
		while ( act < n ) {
			if (act + k > n)
				res.emplace_back(act, n);
			else
				res.emplace_back(act, act+k);
			act += k;
			dist[i]++;
		}
	}

	cout << dist[1] + dist[2] << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].fi << " " << res[i].se << endl;

	return 0;
}