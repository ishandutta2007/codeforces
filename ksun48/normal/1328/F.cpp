#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	sort(a.begin(), a.end());
	for(int i = 0; i + k-1 < n; i++){
		if(a[i] == a[i+k-1]){
			cout << 0 << '\n';
			return 0;
		}
	}
	ll lcost = 0;
	ll rcost = 0;
	for(int i = 0; i < k; i++){
		lcost += a[k-1] - a[i];
		rcost += a[n-1-i] - a[n-k];
	}
	for(int j = k; j < n; j++){
		if(a[k-1] == a[j]) lcost--;
		if(a[n-k] == a[n-1-j]) rcost--;
	}
	ll sum = 0;
	for(int i = 0; i < n-1-i; i++){
		sum += a[n-1-i] - a[i];
	}
	ll ans = min(sum - (n-k), min(lcost, rcost));
	cout << ans << '\n';
}