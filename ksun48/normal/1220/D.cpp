#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	using ll = long long;
	int n;
	cin >> n;
	vector<multiset<ll> > b(64);
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		ll ox = x;
		ll v = 0;
		while(x % 2 == 0){
			x /= 2;
			v += 1;
		}
		b[v].insert(ox);
	}
	int best = 0;
	for(int i = 0; i < 64; i++){
		if(b[i].size() > b[best].size()) best = i;
	}
	cout << n - (int)b[best].size() << '\n';
	for(int i = 0; i < 64; i++){
		if(i == best) continue;
		for(ll a : b[i]){
			cout << a << ' ';
		}
	}
	cout << '\n';
}