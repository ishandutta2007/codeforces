#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, Q;
	cin >> n >> Q;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
		x--;
	}
	int cnt = n;
	vector<pair<int,int> > ops;
	auto merge = [&](int r, int s) -> int {
		if(r == 0) return s;
		if(s == 0) return r;
		cnt++;
		ops.push_back({r, s});
		int z = cnt;
		return z;
	};
	const int B = 8;
	const int T = 12;
	vector<vector<int> > need(1 << T);
	vector<map<pair<int,int>, int> > how(1 << T);
	for(int i = 0; i < n; i++){
		need[a[i]] = {i};
		how[a[i]][{0, 0}] = i+1;
	}
	for(int l = 0; l < B; l++){
		vector<vector<int> > new_need(1 << (T - l - 1));
		vector<map<pair<int,int>, int> > new_how(1 << (T - l - 1));
		for(int j = 0; j < (1 << (T - l)); j += 2){
			vector<int> r = need[j];
			r.insert(r.end(), need[j+1].begin(), need[j+1].end());
			need[j].push_back(-1);
			need[j+1].push_back(-1);

			sort(r.begin(), r.end());
			new_need[j/2] = r;
			vector<pair<int,int> > where(r.size());
			int i0 = 0, i1 = 0;
			for(int q = 0; q < (int)r.size(); q++){
				if(need[j][i0] == r[q]){
					where[q] = {0, i0};
					i0++;
				} else {
					where[q] = {1, i1};
					i1++;					
				}
			}
			for(int st = 0; st < (int)r.size(); st++){
				int first0 = -1, first1 = -1, last0 = -1, last1 = -1;
				for(int en = st; en < (int)r.size(); en++){
					if(where[en].first == 0){
						last0 = where[en].second;
						if(first0 == -1) first0 = where[en].second;
					} else {
						last1 = where[en].second;
						if(first1 == -1) first1 = where[en].second;
					}
					int s0 = 0, s1 = 0;
					if(first0 != -1) s0 = how[j][{first0, last0}];
					if(first1 != -1) s1 = how[j+1][{first1, last1}];
					new_how[j/2][{st, en}] = merge(s0, s1);
				}
			}
		}
		need = new_need;
		how = new_how;
	}
	vector<int> ans;
	for(int i = 0; i < Q; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		int cur = 0;
		for(int j = 0; j < (1 << (T - B)); j++){
			int s = lower_bound(need[j].begin(), need[j].end(), l) - need[j].begin();
			int e = lower_bound(need[j].begin(), need[j].end(), r+1) - need[j].begin();
			if(s < e){
				cur = merge(cur, how[j][{s, e-1}]);
			}
		}
		ans.push_back(cur);
	}
	cout << cnt << '\n';
	for(pair<int,int> r : ops){
		cout << r.first << ' ' << r.second << '\n';
	}
	for(int v : ans) cout << v << ' ';
	cout << '\n';
}