#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> a(m);
	ll sum = 0;
	for(int i = 0; i < m; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum < n){
		cout << -1 << '\n';
		return 0;
	}
	vector<ll> b(m);
	ll cur = n;
	for(int i = m-1; i >= 0; i--){
		sum -= a[i];
		cur = min(sum, min(cur - 1, n - a[i]));
		b[i] = cur;
	}
	if(cur < 0){
		cout << -1 << '\n';
		return 0;
	}
	for(ll x : b){
		cout << (x + 1) << ' ';
	}
	cout << '\n';
}