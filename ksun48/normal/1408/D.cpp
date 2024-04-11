#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int> > a(n), b(m);
	for(pair<int,int>& x : a) cin >> x.first >> x.second;
	for(pair<int,int>& x : b) cin >> x.first >> x.second;
	vector<int> need(1.1e6, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i].first <= b[j].first && a[i].second <= b[j].second){
				int d1 = b[j].first - a[i].first;
				int d2 = b[j].second - a[i].second;
				// X > d1 or Y > d2
				need[d1] = max(need[d1], d2+1);
			}
		}
	}
	int best = 1e7;
	int cmax = 0;
	for(int j = (int)need.size()-1; j >= 0; j--){
		cmax = max(cmax, need[j]);
		best = min(best, j + cmax);
	}
	cout << best << '\n';
}