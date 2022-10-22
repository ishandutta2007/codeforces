#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

vector<int> bfs(auto &E,vector<int> V){
	vector<int> ret(E.size(),Inf);
	queue<int> Q;
	
	for(int i=0;i<V.size();i++){
		ret[V[i]]=0;
		Q.push(V[i]);
	}
	
	while(Q.size()!=0){
		int from = Q.front();
		Q.pop();
		
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i];
			if(ret[to]!=Inf)continue;
			ret[to] = ret[from] + 1;
			Q.push(to);
		}
	}
	
	return ret;
}

int main(){

	int n;
	cin>>n;
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	vector<int> V(1,0);
	
	auto d1 = bfs(E,V);
	
	int maxi = 0;
	int a;
	for(int i=0;i<n;i++){
		if(maxi < d1[i]){
			maxi = d1[i];
			a = i;
		}
	}
	
	V[0] = a;
	
	d1 = bfs(E,V);
	
	maxi = 0;
	int b;
	for(int i=0;i<n;i++){
		if(maxi < d1[i]){
			maxi = d1[i];
			b = i;
		}
	}
	
	V[0] = b;
	
	auto d2 = bfs(E,V);
	
	V.pop_back();
	int now = a;
	while(true){
		V.push_back(now);
		if(now==b)break;
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(d1[now] > d1[to])continue;
			if(d1[now] + d2[to] + 1 == d1[b]){
				now = to;
				break;
			}
		}
	}
	
	auto d3 = bfs(E,V);
	int ans = maxi;
	maxi = 0;
	int c;
	
	for(int i=0;i<n;i++){
		if(maxi<d3[i]){
			maxi = d3[i];
			c = i;
		}
		if(maxi==0){
			if(i!=a&&i!=b)c = i;
		}
	}
	cout<<ans+maxi<<endl;
	cout<<a+1<<' '<<b+1<<' '<<c+1<<endl;
	
	
	return 0;
}