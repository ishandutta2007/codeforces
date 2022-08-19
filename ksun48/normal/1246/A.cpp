#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, p;
	cin >> n >> p;
	for(ll q = 0; q <= 100000; q++){
		ll a = n - p * q;
		if(a >= 0 && __builtin_popcountll(a) <= q && a >= q){
			cout << q << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}