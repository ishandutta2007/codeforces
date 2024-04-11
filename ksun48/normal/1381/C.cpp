#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	int C = n+1;
	vector<int> b(n);
	for(int i = 0; i < n; i++) cin >> b[i];
	// cry
	vector<int> ans(n, 0);
	vector<vector<int> > color_where(C+1);
	for(int i = 0; i < n; i++){
		color_where[b[i]].push_back(i);
	}
	map<int, vector<int> > where_freqs;
	for(int i = 1; i <= C; i++){
		where_freqs[(int)color_where[i].size()].push_back(i);
	}
	y -= x;
	int cn = n - x;
	while(x > 0){
		int a = where_freqs.rbegin()->second.back();
		where_freqs.rbegin()->second.pop_back();
		if(where_freqs.rbegin()->second.empty()){
			where_freqs.erase(where_freqs.rbegin()->first);
		}
		int p = color_where[a].back();
		color_where[a].pop_back();
		ans[p] = a;
		where_freqs[(int)color_where[a].size()].push_back(a);
		x--;
	}
	int mf = where_freqs.rbegin()->first;
	if(2 * (cn - mf) < y){
		cout << "NO" << '\n';
		return;
	}
	int unused = where_freqs[0].front();
	int nm = 0;
	while(where_freqs.size() >= 2 && cn >= 2){
		int a1 = where_freqs.rbegin()->second.back();
		where_freqs.rbegin()->second.pop_back();
		if(where_freqs.rbegin()->second.empty()){
			where_freqs.erase(where_freqs.rbegin()->first);
		}
		int a2 = where_freqs.rbegin()->second.back();
		where_freqs.rbegin()->second.pop_back();
		if(where_freqs.rbegin()->second.empty()){
			where_freqs.erase(where_freqs.rbegin()->first);
		}
		if(color_where[a1].empty()) break;
		if(color_where[a2].empty()) break;
		int p1 = color_where[a1].back();
		color_where[a1].pop_back();
		int p2 = color_where[a2].back();
		color_where[a2].pop_back();
		cn -= 2;
		int a3 = 0;
		int p3 = 0;
		if(cn == 1 && where_freqs.rbegin()->first > 0){
			a3 = where_freqs.rbegin()->second.back();
			where_freqs.rbegin()->second.pop_back();
			if(where_freqs.rbegin()->second.empty()){
				where_freqs.erase(where_freqs.rbegin()->first);
			}
			assert(!color_where[a3].empty());
			p3 = color_where[a3].back();
			color_where[a3].pop_back();
		}
		where_freqs[(int)color_where[a1].size()].push_back(a1);
		where_freqs[(int)color_where[a2].size()].push_back(a2);
		if(a3){
			where_freqs[(int)color_where[a3].size()].push_back(a3);
		}
		if(a3 == 0){
			ans[p1] = a2;
			ans[p2] = a1;
			nm += 2;
		} else {
			ans[p1] = a3;
			ans[p2] = a1;
			ans[p3] = a2;
			nm += 3;
		}
	}
	assert(nm >= y);

	for(int i = 0; i < n; i++){
		if(ans[i] == 0){
			ans[i] = unused;
		} else if(nm > y && ans[i] != b[i]){
			ans[i] = unused;
			nm--;
		}
	}
	for(int i = 0; i < n; i++){
	}
	cout << "YES" << '\n';
	for(int a : ans) cout << a << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}