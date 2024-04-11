#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	if(a.front() != n && a.back() != n){
		cout << -1 << '\n';
		return;
	}
	reverse(a.begin(), a.end());
	for(int x : a) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}