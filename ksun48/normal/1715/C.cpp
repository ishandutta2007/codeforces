#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+2, 0);
	ll ans = n * ll(n+1) / 2;
	for(int i = 0; i < n; i++){
		cin >> a[i+1];
	}
	for(int j = 0; j <= n; j++){
		if(a[j] != a[j+1]){
			ans += j * ll(n - j);
		}
	}
	while(m--){
		int i, x;
		cin >> i >> x;
		for(int j : {i-1, i}){
			if(a[j] != a[j+1]){
				ans -= j * ll(n - j);
			}
		}
		a[i] = x;
		for(int j : {i-1, i}){
			if(a[j] != a[j+1]){
				ans += j * ll(n - j);
			}
		}
		cout << ans << '\n';
	}
}