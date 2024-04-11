#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, s;
int a[N][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i][0];
	for (int i = 1; i <= n; ++i) cin >> a[i][1];
	if (a[1][0] == 0) return cout << "NO\n",0;
	if (a[s][0] == 1) return cout << "YES\n",0;
	if (a[s][1] == 0) return cout << "NO\n",0;
	for (int i = s + 1; i <= n; ++i) if (a[i][0] == 1 && a[i][1] == 1) {
		return cout << "YES\n",0;
	}
	cout << "NO\n";
}