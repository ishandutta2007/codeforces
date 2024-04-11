#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n, r;
	cin >> n >> r;
	vector<int> x(n);
	for(int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(), x.end());
	reverse(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	x.push_back(0);
	for(int i = 0; i < (int)x.size(); i++){
		if(x[i] <= i * r){
			cout << i << '\n';
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int _ = 0; _ < T; _++){
		solve();
	}
}