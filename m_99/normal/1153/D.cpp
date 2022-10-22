#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

vector<int> f;

pair<int,int> dfs(int now,auto &E){
	pair<int,int> ret = {0,0};
	
	if(E[now].size()==0){
		return make_pair(1,1);
	}
	
	vector<pair<int,int>> P;
	
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		
		P.push_back(dfs(to,E));
		ret.second += P.back().second;
	}
	int S = 0;
	for(int i=0;i<P.size();i++){
		if(f[now]==0){
			S += P[i].first-1;
			//ret.first = max(ret.first,P[i].first);
		}
		else{
			ret.first = max(ret.first,ret.second-P[i].second+P[i].first);
		}
	}
	
	if(f[now]==0){
		ret.first = S+1;
	}
	
	return ret;
}
		

int main() {
	
	int n;
	cin>>n;
	
	f.resize(n);
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n-1;i++){
		int p;
		cin>>p;
		p--;
		
		E[p].push_back(i+1);
	}
	
	cout<<dfs(0,E).first<<endl;
	
    return 0;
}