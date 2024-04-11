#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll, ll> > stuff; // sum, cnt
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		ll cc = 1;
		while(!stuff.empty() && stuff.back().first * cc >= stuff.back().second * a){
			cc += stuff.back().second;
			a += stuff.back().first;
			stuff.pop_back();
		}
		stuff.push_back({a, cc});
	}
	cout << fixed << setprecision(12);
	for(pair<ll, ll> r : stuff){
		long double g = r.first;
		g /= (long double)r.second;
		for(int i = 0; i < r.second; i++){
			cout << g << '\n';
		}
	}
}