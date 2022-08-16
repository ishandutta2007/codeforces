#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int N = 101;
int a[N][N];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> a[i][j];
	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	int res = a[0][0];
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			res = max(res, a[i][j]);
	cout << res << endl;

	return 0;
}