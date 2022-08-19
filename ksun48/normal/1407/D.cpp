#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> h(n);
	for(int& x : h) cin >> x;
	vector<vector<int> > edges(n+1);
	for(int _ = 0; _ < 2; _++){
		for(int& x : h) x = -x;
		vector<int> ord(n);
		for(int i = 0; i < n; i++) ord[i] = i;
		sort(ord.begin(), ord.end(), [&](int a, int b){
			return tie(h[a], a) < tie(h[b], b);
		});
		set<int> cur;
		for(int j = 0; j < n; j++){
			int p = ord[j];
			cur.insert(p);
			auto f = cur.find(p);
			if(f != cur.begin()){
				int l = *prev(f);
				edges[l].push_back(p);
			}
			auto g = next(f);
			if(g != cur.end()){
				int r = *g;
				if(j + 1 < n && h[ord[j+1]] == h[ord[j]] && ord[j+1] < r){
				} else {
					edges[p].push_back(r);
				}
			}
		}
	}
	vector<int> dp(n, 1e8);
	dp.back() = 0;
	for(int i = n-1; i >= 0; i--){
		for(int j : edges[i]){
			dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	cout << dp.front() << '\n';
}