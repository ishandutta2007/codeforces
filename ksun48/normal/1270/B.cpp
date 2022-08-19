#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i + 1 < n; i++){
		if(abs(a[i] - a[i+1]) >= 2){
			cout << "YES" << '\n';
			cout << i + 1 << ' ' << i+2 << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}