#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n;
string s;
vvi dp(5005, vi(5005, -1));
vi res(5005);

int obtRes (int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == j)
		return dp[i][j] = 1;

	if (j - i == 1)
		if (s[i] == s[j] )
			return dp[i][j] = 2;
		else
			return dp[i][j] = 0;

	if (obtRes(i+1, j-1))
		if (s[i] == s[j]) {
			int l = (j - i + 1) / 2;
			return dp[i][j] = obtRes(i, i+l-1) + 1;
		} else {
			return dp[i][j] = 0;
		}

	return dp[i][j] = 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) 
			res[obtRes(i, j)]++;

	for (int i = n-1; i; i--)
		res[i] += res[i+1];

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}