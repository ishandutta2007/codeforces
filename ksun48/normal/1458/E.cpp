#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	using ll = long long;
	map<ll,ll> xlose;
	map<ll,ll> ylose;
	set<pair<ll,ll> > lose;
	map<ll, map<ll, ll> > lose_by_diff;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		if(!xlose.count(a)) xlose[a] = b;
		if(!ylose.count(b)) ylose[b] = a;
		xlose[a] = min(xlose[a], b);
		ylose[b] = min(ylose[b], a);
		lose.insert({a, b});
	}
	const ll INF = ll(1e15);
	ll cx = 0;
	ll cy = 0;
	while(true){
		if(xlose.count(cx) && xlose[cx] <= cy){
			cx++;
			continue;
		}
		if(ylose.count(cy) && ylose[cy] <= cx){
			cy++;
			continue;
		}
		if(xlose.count(cx) || ylose.count(cy)){
			lose.insert({cx, cy});
			cx++; cy++;
			continue;
		}
		auto vx = xlose.upper_bound(cx);
		auto vy = ylose.upper_bound(cy);
		ll add = INF;
		if(vx != xlose.end()){
			add = min(add, (*vx).first - cx);
		}
		if(vy != ylose.end()){
			add = min(add, (*vy).first - cy);
		}
		lose_by_diff[cy-cx][cx+add] = cx;
		if(add == INF) break;
		cx += add;
		cy += add;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		bool ans = false;
		if(lose.count({a, b})) ans = true;
		auto& d = lose_by_diff[b-a];
		auto r = d.upper_bound(a);
		if(r != d.end() && (*r).second <= a){
			ans = true;
		}
		cout << (ans ? "LOSE" : "WIN") << '\n';
	}
}