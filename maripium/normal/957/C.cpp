#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,u;
int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> u;
	vector<double> e(n);
	double ans = 0;;
	for(int i = 0;i < n;++i) cin >> e[i];
	for(int i = 0;i < n - 2;++i) {
		if(e[i + 2] - e[i] > u) continue;
		int k = upper_bound(e.begin(),e.end(),e[i] + u) - e.begin() - 1;
 		ans = max(ans,(e[k] - e[i + 1]) / (e[k] - e[i]));
	}
	if(ans != 0)cout << fixed << setprecision(10) << ans << endl;
	else cout << -1;
}