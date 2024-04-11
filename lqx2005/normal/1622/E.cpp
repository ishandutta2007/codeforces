#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 10, M = 1e4 + 10;
int n, m, x[N], s[M][N], coef[M], ord[M], res[M];
void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < n; i++) {
		string b;
		cin >> b;
		for(int j = 0; j < m; j++) s[j + 1][i] = b[j] - '0';
	}
	int ans = -1;
	for(int i = 0; i < 1 << n; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) sum += x[j];
			else sum -= x[j];
		}
		for(int j = 1; j <= m; j++) {
			coef[j] = 0;
			for(int k = 0; k < n; k++) {
				if(s[j][k]) coef[j] += (i >> k & 1) ? -1 : 1;
			}
			ord[j] = j;
		}
		sort(ord + 1, ord + m + 1, [&](int x, int y) {return coef[x] < coef[y]; });
		for(int j = 1; j <= m; j++) sum += j * coef[ord[j]];
		if(ans < sum) {
			for(int j = 1; j <= m; j++) res[ord[j]] = j;
			ans = sum;
		}
	}
	// cout << ans << endl;
	for(int i = 1; i <= m; i++) cout << res[i] <<" ";
	cout << endl;
	return;
}
int main() {
	int t;
	for(cin >> t; t--; solve());
    return 0;
}