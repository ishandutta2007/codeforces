#include<bits/stdc++.h>
using namespace std;
int ans;
int l;

void dfs(int node, int par, set<int> G[]) {
	//cout<<"B "<<node<<' '<<G[node].size()<<endl;
	vector<int> v;
	for(auto it: G[node]) {
		v.push_back(it);
	}
	for(auto it: v) {
		if(it == par)
			continue;
		dfs(it,node,G);
	}
	//cout<<"A "<<node<<' '<<G[node].size()<<endl;
	if(node != 0 && G[node].size() != 1) {
		G[par].erase(node);
		ans += G[node].size()-2;
	}
	else if(node != 0 && par == 0) {
		l++;
	}
}
 
int main() {
    int T; cin>>T;
    while(T--) {
    	ans = 0; l = 0;
        int n; cin>>n;
        set<int> G[n];
        for(int i=0;i<n-1;i++) {
        	int a,b; cin>>a>>b; a--,b--;
        	G[a].insert(b);
        	G[b].insert(a);
        }
        dfs(0,0,G);
        cout<<ans+max(1,l)<<endl;
    }
    return 0;
}