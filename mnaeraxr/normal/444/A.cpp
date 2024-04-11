#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int val[600];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> val[i];

	double answer = 0.0;

	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;

		double cur = 1.0 * (val[u] + val[v]) / w;

		answer = max(answer, cur);
	}

	cout.precision(17);
	cout << fixed << answer << endl;

	return 0;
}