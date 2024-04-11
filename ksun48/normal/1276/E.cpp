#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<pair<ll, ll>, ll> sig(vector<ll> a){
	ll r1 = a[1] - a[0];
	ll r2 = a[2] - a[1];
	ll r3 = a[3] - a[2];
	ll g = __gcd(__gcd(r1, r2), r3);
	if(g == 0){
		return {{0, a[0]}, 0};
	}
	ll f = ((a[0] % g) + g) % g;

	ll res = 0;
	for(int j = 0; j < 4; j++) res += ((a[j] - f) / g) & 1;
	return {{g, f}, res};
}

bool between(ll x, ll a, ll b){
	return (a <= x && x <= b) || (b <= x && x <= a);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	function<void(vector<ll>&, vector<pair<ll, ll> >&)> solve;
	solve = [&](vector<ll>& v, vector<pair<ll, ll> >& moves) {
		auto make = [&](int i, int j) {
			moves.push_back({v[i], v[j]});
			v[i] = 2 * v[j] - v[i];
		};
		while(true){
			sort(v.begin(), v.end());
			if(v[0] == v[3]){
				// nothing
			} else if(v[0] + 1 < v[3]){
				ll th = (v[3] - v[0]) / 8;
				// get to a, a+1 only
				for(int j = 1; j <= 2; j++){
					if(v[j] - v[0] > th && v[3] - v[j] > th){
						if(v[3] - v[j] > v[j] - v[0]){
							make(0, j); goto done;
						} else {
							make(3, j); goto done;
						}
					}
				}
				if(v[1] - v[0] > th){
					make(3, 1); continue;
				}
				if(v[3] - v[2] > th){
					make(0, 2); continue;
				}
				if(v[2] - v[1] > th){
					if(v[1] - v[0] > v[3] - v[2]){
						make(2, 1); make(2, 0); continue;
					} else {
						make(1, 2); make(1, 3); continue;
					}
				}
				assert(false);
			} else if(v[0] == 0){
				// nothing
			} else if(v[3] == 0 && v[0] < 0){
				for(int i = 0; i < 3; i++){
					make(i, 3);
				}
				continue;
			} else {
				if(v[0] == v[2] && v[3] > 0) make(3, 0);
				if(v[1] == v[3] && v[0] < 0) make(0, 3);
				sort(v.begin(), v.end());
				bool flag = false;
				if(v[1] == v[3]) flag = true;
				if(v[1] != v[2] && 0 < v[0]) flag = true;

				if(flag) reverse(v.begin(), v.end());
				while(!between(0, v[0], v[3])){
					make(1, 3); sort(v.begin(), v.end()); if(flag) reverse(v.begin(), v.end());
				}
				while(abs(v[0] - v[3]) > 1){
					make(3, 2); sort(v.begin(), v.end()); if(flag) reverse(v.begin(), v.end());
					while(!between(0, v[0], v[3])){
						make(0, 3);
						make(1, 3);
						make(2, 3);
						flag = !flag;
					}
				}
				sort(v.begin(), v.end());
				assert(abs(v[0] - v[3]) <= 1);
				continue;
			}
			break;
			done:;
			continue;
		}
	};

	vector<vector<ll> > a(2, vector<ll>(4));
	for(int x = 0; x < 2; x++){
		for(int i = 0; i < 4; i++){
			cin >> a[x][i];
		}
		sort(a[x].begin(), a[x].end());
	}
	if(sig(a[0]) != sig(a[1])){
		cout << -1 << '\n';
		return 0;
	}
	ll g = sig(a[0]).first.first;
	ll f = sig(a[0]).first.second;
	if(g == 0){
		cout << 0 << '\n';
		return 0;
	}
	for(int j = 0; j < 2; j++){
		for(ll& x : a[j]){
			x = (x - f) / g;
		}
	}
	vector<vector<pair<ll, ll> > > moves(2);
	solve(a[0], moves[0]);
	solve(a[1], moves[1]);

	for(pair<ll, ll>& x : moves[1]){
		x.first = x.second * 2 - x.first;
	}
	reverse(moves[1].begin(), moves[1].end());
	moves[0].insert(moves[0].end(), moves[1].begin(), moves[1].end());

	vector<pair<ll, ll> > real_moves;
	for(pair<ll, ll> x : moves[0]){
		if(x.first == x.second) continue;
		real_moves.push_back(x);
	}
	cout << real_moves.size() << '\n';
	for(pair<ll, ll> x : real_moves){
		if(x.first == x.second) continue;
		cout << x.first * g + f << ' ' << x.second * g + f << '\n';
	}
}