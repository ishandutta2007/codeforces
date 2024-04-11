#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<set<int> > locs(n+1);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		locs[a[i]].insert(i);
	}
	vector<int> ans;
	int cur = 0;
	while(cur < n){
		int ncur = cur+1;
		int f = 0;
		while(!locs[f].empty()){
			if(*locs[f].begin() < cur){
				locs[f].erase(locs[f].begin());
			} else {
				ncur = max(ncur, *locs[f].begin() + 1);
				f++;
			}
		}
		ans.push_back(f);
		cur = ncur;
	}
	cout << ans.size() << '\n';
	for(int x : ans) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}