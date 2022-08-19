#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(3*n);
	vector<pair<int,int> > f(m);
	set<int> okay;
	for(int i = 0; i < m; i++){
		okay.insert(i);
		int a, b;
		cin >> a >> b;
		a--; b--;
		f[i] = {a, b};
		edges[a].push_back(i);
		edges[b].push_back(i);
	}
	set<int> taken;
	set<int> vleft;
	for(int i = 0; i < 3*n; i++) vleft.insert(i);
	while(taken.size() < n && !okay.empty()){
		int x = *okay.begin();
		for(int e : edges[f[x].first]) okay.erase(e);
		for(int e : edges[f[x].second]) okay.erase(e);
		vleft.erase(f[x].first);
		vleft.erase(f[x].second);
		taken.insert(x);
	}
	if(taken.size() >= n){
		assert(taken.size() == n);
		cout << "Matching" << '\n';
		for(int x : taken){
			cout << x + 1 << ' ';
		}
		cout << '\n';
	} else {
		assert(vleft.size() >= n);
		cout << "IndSet" << '\n';
		size_t cur = 0;
		for(int x : vleft){
			cout << x + 1 << ' ';
			cur += 1;
			if(cur == n) break;
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		solve();
	}
}