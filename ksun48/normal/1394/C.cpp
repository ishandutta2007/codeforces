#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int,int> > vals;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int a = 0, b = 0;
		for(char c : s){
			if(c == 'B') a++;
			if(c == 'N') b++;
		}
		vals.push_back({a, b});
	}
	int s = -1;
	int e = 1e6; // yes
	pair<int,int> ans;
	int a1 = 1e6, a2 = -1e6, b1 = 1e6, b2 = -1e6, c1 = 1e6, c2 = -1e6;
	for(int i = 0; i < n; i++){
		a1 = min(a1, vals[i].first);
		a2 = max(a2, vals[i].first);
		b1 = min(b1, vals[i].second);
		b2 = max(b2, vals[i].second);
		c1 = min(c1, vals[i].first - vals[i].second);
		c2 = max(c2, vals[i].first - vals[i].second);
	}
	while(s + 1 < e){
		int l = (s + e) / 2;
		bool works = false;
		int x1 = a2 - l;
		int x2 = a1 + l;
		int y1 = b2 - l;
		int y2 = b1 + l;
		int z1 = c2 - l;
		int z2 = c1 + l;
		vector<pair<int,int> > cands;
		cands.push_back({x1, y1});
		cands.push_back({x1, y2});
		cands.push_back({x2, y1});
		cands.push_back({x2, y2});

		cands.push_back({x1, x1-z1});
		cands.push_back({x1, x1-z2});
		cands.push_back({x2, x2-z1});
		cands.push_back({x2, x2-z2});

		cands.push_back({y1+z1, y1});
		cands.push_back({y1+z2, y2});
		cands.push_back({y2+z1, y1});
		cands.push_back({y2+z2, y2});
		for(pair<int,int> r : cands){
			if(r.first == 0 && r.second == 0) continue;
			if(r.first < 0 || r.second < 0) continue;
			if(r.first < x1 || r.first > x2) continue;
			if(r.second < y1 || r.second > y2) continue;
			if(r.first - r.second < z1 || r.first - r.second > z2) continue;
			works = true;
			ans = r;
		}
		if(works){
			e = l;
		} else {
			s = l;
		}
	}
	cout << e << '\n';
	cout << string(ans.first, 'B') << string(ans.second, 'N') << '\n';
}