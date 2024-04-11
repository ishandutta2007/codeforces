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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, k, dp[1005][2005], rec[1005][2005];
string s;

bool obtRes (int i, int j) {
	if (i == n)
		return abs(j - 1000) == k;

	if (abs(j - 1000) == k)
		return 0;

	int &res = dp[i][j];
	if (res != -1)
		return res;

	if (s[i] == 'W') {
		rec[i][j] = 1;
		return res = obtRes(i+1, j+1);
	}

	if (s[i] == 'L') {
		rec[i][j] = -1;
		return res = obtRes(i+1, j-1);
	}

	if (s[i] == 'D') {
		rec[i][j] = 0;
		return res = obtRes(i+1, j);
	}

	if (obtRes(i+1, j+1)) {
		rec[i][j] = 1;
		return res = 1;
	}

	if (obtRes(i+1, j)) {
		rec[i][j] = 0;
		return res = 1;
	}

	if (obtRes(i+1, j-1)) {
		rec[i][j] = -1;
		return res = 1;
	}

	return res = 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 2005; j++)
			dp[i][j] = rec[i][j] = -1;

	cin >> n >> k >> s;
	if (obtRes(0, 1000)) {
		int i = 0, j = 1000;

		for (int i = 0; i < n; i++) {
			if (rec[i][j] == -1) {
				cout << "L";
				j--;
			} else if (rec[i][j]) {
				cout << "W";
				j++;
			} else {
				cout << "D";
			}
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

    return 0;
}