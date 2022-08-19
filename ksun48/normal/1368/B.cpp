#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	ll n;
	cin >> n;
	string g = "codeforces";
	vector<ll> a(g.size(), 0);
	int idx = 0;
	while(true){
		a[idx]++;
		idx += 1;
		if(idx == (int)g.size()) idx = 0;
		ll prod = 1;
		for(ll r : a) prod *= r;
		if(prod >= n) break;
	}
	for(int i = 0; i < (int)g.size(); i++){
		cout << string(a[i], g[i]);
	}
	cout << '\n';
}