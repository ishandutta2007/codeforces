#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

ll query(int t, int i, int j, int k){
	cout << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
	cout << flush;
	ll res;
	cin >> res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int a = 0;
	int b = 1;
	for(int i = 2; i < n; i++){
		if(query(2, a, b, i) == 1) b = i;
	}
	vector<pair<ll, int> > areas;
	for(int j = 0; j < n; j++){
		if(j == a || j == b) continue;
		areas.push_back({query(1, a, b, j), j});
	}
	sort(areas.begin(), areas.end());
	reverse(areas.begin(), areas.end());

	int c = areas.front().second;
	vector<int> side1;
	vector<int> side2;
	for(auto f : areas){
		if(f.second == c || query(2, a, c, f.second) == 1){
			side1.push_back(f.second);
		} else {
			side2.push_back(f.second);
		}
	}
	side1.push_back(b);
	side2.push_back(a);
	reverse(side2.begin(), side2.end());
	for(int x : side1) side2.push_back(x);
	cout << 0;
	for(int x : side2){
		cout << ' ' << x + 1;
	}
	cout << '\n';
	cout << flush;
}