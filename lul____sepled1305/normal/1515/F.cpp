#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
int x;
 
const int N = 3e5+10;
map<int,int> mp[N];
int a[N], p[N];
vector<int> G[N], T[N], ll[N];
vector<pii> ans;
 
void makeTree(int par,int node) {
	if(p[node] != -1)
		return;
		
	p[node] = par;
	if(node != 0)
		T[par].push_back(node);
	
	for(auto it: G[node]) {
		if(it != par)
			makeTree(node,it);
	}
}
 
void makePath(int node) {
	for(auto it: ll[node]) {
		ans.push_back({node,it});
		makePath(it);
	}
}
 
int recur(int node) {
	int cur = a[node];
	vector<pii> edge;
	for(auto it: T[node]) {
		edge.push_back({recur(it),it});
	}
	sort(edge.begin(),edge.end(),greater<pii>());
	for(auto it: edge) {
		cur = cur + it.first - x;
		if(cur >= 0) {
			ans.push_back({node,it.second});
			makePath(it.second);
		}
		else {
			ll[node].push_back(it.second);
		}
	}
	return cur;
}
 
main() {
	int n,m; cin>>n>>m>>x;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		p[i] = -1;
	}
	for(int i=0;i<m;i++) {
		int a,b; cin>>a>>b; a--,b--;
		mp[a].insert({b,i+1});
		mp[b].insert({a,i+1});
		G[a].push_back(b);
		G[b].push_back(a);
	}
	makeTree(0,0);
	if(recur(0) < 0)
		cout<<"NO\n";
	else {
		cout<<"YES\n";
		for(auto it: ans)
			cout<<mp[it.first][it.second]<<endl;
	}
	return 0;
}