#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<pair<int,int> > rows;
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		if(i & 1){
			for(int j = 0; j < m; j++){
				rows.push_back({i, j});
			}
		} else {
			for(int j = 0; j < m; j++){
				rows.push_back({i, m-1-j});
			}
		}
	}
	int p = 0;
	while(k > 1){
		cout << 2 << ' ';
		cout << rows.back().first + 1 << ' ' << rows.back().second + 1 << ' ';
		rows.pop_back();
		cout << rows.back().first + 1 << ' ' << rows.back().second + 1 << '\n';
		rows.pop_back();
		k--;
	}
	cout << rows.size();
	for(pair<int,int> a : rows){
		cout << ' ' << a.first + 1 << ' ' << a.second + 1;
	}
}