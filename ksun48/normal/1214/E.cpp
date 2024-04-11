#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	vector<pair<int,int> > x;
	for(int i = 0; i < n; i++){
		x.push_back({d[i], i});
	}
	sort(x.begin(), x.end());
	reverse(x.begin(), x.end());
	vector<int> path(2 * n, -1);
	vector<vector<int> > extras(2 * n);
	int cur = n;
	int fi = 0;
	for(pair<int,int> r : x){
		if(cur - r.first < n){
			path[cur] = r.second * 2;
			path[cur - r.first] = r.second * 2 + 1;
			cur += 1;
		} else {
			while(path[fi] != -1) fi += 1;
			path[fi] = r.second * 2;
			extras[fi + r.first - 1].push_back(r.second * 2 + 1);
		}
	}
	for(int i = 0; i + 1 < cur; i++){
		cout << 1 + path[i] << " " << 1 + path[i+1] << '\n';
	}
	for(int i = 0; i < 2*n; i++){
		for(int a : extras[i]){
			cout << 1 + path[i] << " " << 1 + a << '\n';
		}
	}
}