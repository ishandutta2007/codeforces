#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int nd = 0;
	for(int i = 0; i + 1 < n; i++){
		if(a[i] < a[i+1]) nd++;
	}
	if(nd == 0){
		cout << 1 << '\n';
	} else if(k == 1){
		cout << -1 << '\n';
	} else {
		cout << (nd + k-2) / (k-1) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}