#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using ordered_set = tree<int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++) cin >> A[i];
	vector<pair<int,int> > z;
	for(int i = 0; i < n; i++){
		z.push_back({-A[i], i});
	}
	sort(z.begin(), z.end());
	int m;
	cin >> m;
	vector<int> k(m), pos(m);
	vector<int> ans(m);
	vector<vector<int> > queries(n+1);
	for(int i = 0; i < m; i++){
		cin >> k[i] >> pos[i];
		pos[i]--;
		queries[k[i]].push_back(i);
	}
	ordered_set X;
	for(int a = 1; a <= n; a++){
		int b = z[a-1].second;
		X.insert(b);
		for(int f : queries[a]){
			ans[f] = A[*X.find_by_order(pos[f])];
		}
	}
	for(int i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
}