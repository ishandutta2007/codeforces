#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	set<pair<int,int>> odd, even;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i + j) & 1){
				odd.insert({i, j});
			} else {
				even.insert({i, j});
			}
		}
	}
	for(int t = 0; t < n*n; t++){
		int a;
		cin >> a;
		if(odd.size() && even.size()){
			int c = (a == 1) ? 2 : 1;
			set<pair<int,int>>& x = (c == 1) ? odd : even;
			pair<int,int> f = *x.begin();
			x.erase(f);
			cout << c << ' ' << (f.first + 1) << ' ' << (f.second + 1) << '\n';
			cout << flush;
		} else {
			set<pair<int,int>>& x = even.empty() ? odd : even;
			int wh = even.empty() ? 1 : 2;
			pair<int,int> f = *x.begin();
			x.erase(f);
			int c = (a == 3) ? (wh) : 3;
			cout << c << ' ' << (f.first + 1) << ' ' << (f.second + 1) << '\n';
			cout << flush;
		}
	}
}