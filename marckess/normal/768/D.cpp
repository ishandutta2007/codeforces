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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int k, q, p;
ld dp[MX][10*MX];

ld obtRes (int i, int j) {
	if (i == k) return 1;
	if (!j) return 0;

	ld &res = dp[i][j];
	if (res != -1) return res;

	return res = ld(i) / k * obtRes(i, j-1) + ld(k - i) / k * obtRes(i+1, j-1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < 10 * MX; j++)
			dp[i][j] = -1;

	cin >> k >> q;

	while (q--) {
		cin >> p;

		for (int i = 1; i < 10 * MX; i++) {
			if (obtRes(0, i) > (p - 1e-7) / 2000) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}