#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	using ll = long long;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << -a[0] << '\n';		
	} else {
		cout << 2 << ' ' << n << '\n';
		for(int i = 1; i < n; i++){
			cout << (n-1) * a[i] << ' ';
		}
		cout << '\n';
		cout << 1 << ' ' << n << '\n';
		for(int i = 0; i < n; i++){
			cout << -n * a[i] << ' ';
		}
		cout << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << (n-1) * a[0] << '\n';
	}
}