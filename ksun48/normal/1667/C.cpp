#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int,int> > locs;
	int r = (n - 1) / 3;
	for(int j = 0; j <= r; j++){
		locs.push_back({j, r-j});
	}
	for(int j = 0; j < r; j++){
		locs.push_back({r+1+j, r+1+(r-1-j)});
	}
	if(n % 3 == 0){
		locs.push_back({n-1, n-1});
	}
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		bool works = false;
	// 		for(auto [x, y] : locs){
	// 			if(x == i || y == j || x-i == y-j){
	// 				works = true;
	// 			}
	// 		}
	// 		if(!works){
	// 			cerr << i << ' ' << j << '\n';
	// 			assert(false);
	// 		}
	// 	}
	// }
	cout << locs.size() << '\n';
	for(auto [a, b] : locs){
		cout << (a+1) << ' ' << (b+1) << '\n';
	}
}