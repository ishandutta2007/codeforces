#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int minv = n;
	int maxv = -1;
	for(int i = 0; i + 1 < n; i++){
		if(a[i] == a[i+1]){
			minv = min(minv, i);
			maxv = max(maxv, i);
		}
	}
	if(maxv == -1 || minv == maxv){
		cout << 0 << '\n';
	} else if(maxv - minv == 1){
		cout << 1 << '\n';
	} else {
		cout << (maxv - minv - 1) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}