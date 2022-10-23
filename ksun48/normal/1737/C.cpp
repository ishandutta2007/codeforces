#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	set<pair<int,int> > s;
	set<pair<int,int> > r;
	int mx = 0, my = 0;
	for(int j = 0; j < 3; j++){
		int a, b;
		cin >> a >> b;
		r.insert({a & 1, b & 1});
		s.insert({a, b});
		mx ^= (a & 1);
		my ^= (b & 1);
	}
	pair<int,int> vertex;
	for(auto [x, y] : s){
		int d = 0;
		for(auto [f, g] : s){
			d += abs(x - f) + abs(y - g);
		}
		if(d == 2) vertex = {x, y};
	}
	int a, b;
	cin >> a >> b;
	if(!r.count({a & 1, b & 1})){
		cout << "NO" << '\n';
	} else if(s.count({a, b})){
		cout << "YES" << '\n';
	// } else if((a == 1 || a == N) && (b == 1 || b == N) && (mx == ((a ^ 1) & 1)) && (my == ((b ^ 1) & 1))){
	// 	cout << "NO" << '\n';
	} else if((vertex.first == 1 || vertex.first == N) && (vertex.second == 1 || vertex.second == N)){
		if(a == vertex.first || b == vertex.second){
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} else {
		cout << "YES" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}