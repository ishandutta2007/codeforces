#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	k = min(k, m-1);
	int no = m-1-k;
	int best = 0;
	for(int ml = 0; ml <= k; ml++){
		int worst = 2e9;
		for(int nl = 0; nl <= no; nl++){
			int l = nl + ml;
			int r = k + no - l;
			worst = min(worst, max(a[l], a[n-1-r]));
		}
		best = max(best, worst);
	}
	cout << best << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}