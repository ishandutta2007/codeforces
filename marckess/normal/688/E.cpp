#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k, c;
bool dp[2][505][505] = {false};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	dp[1][0][0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> c;
		int a = i % 2, b = 1 - a;

		for (int x = 0; x <= k; x++) {
			for (int s = 0; s <= k; s++) {
				dp[a][x][s] = dp[b][x][s];

				if (s - c >= 0) {
					dp[a][x][s] |= dp[b][x][s-c];

					if (x - c >= 0) {
						dp[a][x][s] |= dp[b][x-c][s-c];
					}
				}
			}
		}
	}

	vi res;
	for (int x = 0; x <= k; x++)
		if (dp[1-n%2][x][k])
			res.push_back(x);

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}