#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s += a[i];
	}
	if(s == 0){
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		sort(a.begin(), a.end());
		if(s > 0){
			reverse(a.begin(), a.end());
		}
		for(int x : a) cout << x << ' ';
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}