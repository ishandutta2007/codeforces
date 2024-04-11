#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(2*n);
	for(int& x : a) cin >> x;
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ' << a[i+n] << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}