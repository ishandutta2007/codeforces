#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	using ll = int64_t;
	vector<ll> a(n);
	for(ll& x : a){
		cin >> x;
	}
	vector<ll> b(n);
	for(int i = 0; i < n-1; i++){
		if(a[i] < 0){
			cout << "No" << '\n';
			return;
		}
		b[i] = a[i];
		a[i] -= b[i];
		a[i+1] += b[i];
	}
	if(a[n-1] != 0){
		cout << "No" << '\n';
		return;
	}
	for(int i = 0; i < n-1; i++){
		if(b[i] == 0 && b[i+1] != 0){
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}