#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi;
#define second se;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vvi dp;
int n, c[100005];
vector<string> vs;

ll obtRes (int i, int f) {
	if (i == n)
		return 0;

	if (dp[i][f] != -1)
		return dp[i][f];

	string ant = vs[i-1];
	if (f == 1)
		reverse(ant.begin(), ant.end());

	ll res = 1e18;
	string act = vs[i];

	if (ant.compare(act) <= 0)
		res = min(res, obtRes(i+1, 0));

	reverse(act.begin(), act.end());
	if (ant.compare(act) <= 0)
		res = min(res, obtRes(i+1, 1) + c[i]);

	return dp[i][f] = res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	dp = vvi(n, vi(2, -1));
	vs = vector<string>(n);

	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		cin >> vs[i];

	ll res = min(obtRes(1, 1) + c[0], obtRes(1, 0));

	if (res == 1e18)
		cout << -1 << endl;
	else
		cout << res << endl;
	
	return 0;
}