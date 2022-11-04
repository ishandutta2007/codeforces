#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi
#define second se
#define SET(p,n) memset(p, n, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

string s;
vvi dp(5005, vi(5, -1));

int obtRes (int i, int f) {
	if (i == s.size())
		return s.size();

	if (dp[i][f] != -1)
		return dp[i][f];

	if (f == 0)
		if (s[i] == 'b')
			return dp[i][f] = max(obtRes(i, f+1), obtRes(i+1, f) - 1);
		else
			return dp[i][f] = obtRes(i+1, f);

	if (f == 1)
		if (s[i] == 'a')
			return dp[i][f] = max(obtRes(i, f+1), obtRes(i+1, f) - 1);
		else
			return dp[i][f] = obtRes(i+1, f);

	if (f == 2)
		if (s[i] == 'b')
			return dp[i][f] = obtRes(i+1, f) - 1;
		else
			return dp[i][f] = obtRes(i+1, f);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;

	cout << obtRes(0, 0) << endl;

	return 0;
}