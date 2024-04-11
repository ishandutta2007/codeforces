#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
	}
	if(n & 1){
		cout << "NO" << '\n';
		return;
	}
	sort(a.begin(), a.end());
	vector<int> b;
	for(int i = 0; i < n/2; i++){
		b.push_back(a[i]);
		b.push_back(a[i + n/2]);
	}
	for(int i = 0; i < n; i++){
		if(b[i] == b[(i+1) % n]){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
	for(int x : b) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}