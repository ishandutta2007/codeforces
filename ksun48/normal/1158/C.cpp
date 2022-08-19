#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;

vector<int> perm;
int r = 0;

void dfs(int x){
	r--; perm[x] = r;
	for(int a : edges[x]){
		dfs(a);
	}
}

void solve(){
	int n;
	cin >> n;
	vector<int> next(n);
	edges.assign(n+1, {});
	vector<pair<int, pair<int,int> > > q;
	for(int i = 0; i < n; i++){
		cin >> next[i];
		if(next[i] == -1){
			next[i] = i+1;
		} else {
			next[i]--;
		}
		edges[next[i]].push_back(i);
		q.push_back({i, {1, -i}});
		q.push_back({next[i], {0, -i}});
	}
	sort(q.begin(), q.end());
	vector<pair<int, pair<int,int> > > st;
	int ok = 1;
	for(auto v : q){
		if(v.second.first == 1){
			st.push_back(v);
		} else {
			if(st.empty() || v.second.second != st.back().second.second){
				ok = false;
				break;
			} else {
				st.pop_back();
			}
		}
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	perm.assign(n+1, -1);
	r = n+1;
	dfs(n);
	// verify permutation
	for(int i = 0; i < n; i++){
		cout << 1 + perm[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}