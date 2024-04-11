#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n, m;
	cin >> n >> m;
	if(m > n) m = n;
	ll s = -1;
	ll e = 2e9;
	while(s + 1 < e){
		ll mid = (s + e) / 2;
		ll val = mid * (mid + 1) / 2;
		if(val >= n-m){
			e = mid;
		} else {
			s = mid;
		}
	}
	cout << m + e << '\n';
}