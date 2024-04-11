#include <bits/stdc++.h>
using namespace std;
#define modulo h
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

vector<int> color;

void dfs1(auto &E,int now,int parent,auto &V){
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		dfs1(E,to,now,V);
		V[now] += max(0,V[to]);
	}
	
	if(color[now]==1)V[now]++;
	else V[now]--;
	return;
}

void dfs2(auto &E,int now,int parent,auto &V,auto &ans,int X){
	int temp = max(X,0);
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(parent==to)continue;
		
		temp += max(V[to],0);
	}
	
	ans[now] = max(X,0)+V[now];
	
	if(color[now]==1)temp++;
	else temp--;
	
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(parent==to)continue;
		
		dfs2(E,to,now,V,ans,temp-max(V[to],0));
	}
}

int main(){
	
	int n;
	cin>>n;
	
	color.resize(n);
	for(int i=0;i<n;i++)scanf("%d",&color[i]);
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	vector<int> child_ans(n,0);
	
	dfs1(E,0,-1,child_ans);
	/*
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<child_ans[i];
	}
	cout<<endl;
	*/
	vector<int> ans(n);
	
	dfs2(E,0,-1,child_ans,ans,0);
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}