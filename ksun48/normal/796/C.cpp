#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	multiset<int> weights;
	for(int i = 0; i < n; i++){
		weights.insert(a[i] + 2);
	}
	int best_ans = *weights.rbegin();
	for(int i = 0; i < n; i++){
		weights.erase(weights.find(a[i] + 2));
		int cur_ans = a[i];
		for(int j : edges[i]){
			weights.erase(weights.find(a[j] + 2));
			cur_ans = max(cur_ans, a[j] + 1);
		}
		if(!weights.empty()) cur_ans = max(cur_ans, *weights.rbegin());
		best_ans = min(best_ans, cur_ans);
		weights.insert(a[i] + 2);
		for(int j : edges[i]){
			weights.insert(a[j] + 2);
		}
	}
	cout << best_ans << '\n';
}