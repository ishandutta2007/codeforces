#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> g(n);
	for (int i = 0; i < n; ++i)
		cin >> g[i];

	int ans = 0;
	sort(g.begin(), g.end());
	for (int i = 0, j; i < n; i = j){
		for (j = i; j < n && g[j] == g[i]; ++j);
		ans += (j - i) * (n - j);
	}

	cout << ans << endl;

	return 0;
}