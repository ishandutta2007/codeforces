#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> ps;
	for(ll p = 2; p * p <= n; p++){
		if(n % p == 0) ps.push_back(p);
		while(n % p == 0){
			n /= p;
		}
	}
	if(n > 1) ps.push_back(n);
	if (ps.size() == 1){
		cout << ps.front() << '\n';
	} else {
		cout << 1 << '\n';
	}
}