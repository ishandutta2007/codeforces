#include<bits/stdc++.h>

using namespace std;

const int maxn = 50;
const int INF = 1e6;

int chtype(char ch)
{
	if (ch == '#' || ch == '&' || ch == '*') return 0;
	if ('0' <= ch && ch <= '9') return 1;
	return 2;
}


int mind[maxn][3];
string s[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		fill_n(mind[i], 3, INF);
		for (int j = 0; j < m; j++) {
			mind[i][chtype(s[i][j])] = min(mind[i][chtype(s[i][j])], min(j, m - j));
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == j || i == k || j == k) continue;

				ans = min(ans, mind[i][0] + mind[j][1] + mind[k][2]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}