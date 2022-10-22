#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

vector<vector<int>> E;
vector<int> ans;

void dfs(int cur,int p,int d){
	int c = 0;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur,d+1);
		c++;
	}
	if(d==0){
		ans[cur] = -c;
	}
	else if(d%2==1){
		ans[cur] = 1+c;
		
	}
	else{
		ans[cur] = -1-c;
	}
	
}
int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		E.assign(n,vector<int>());
		rep(i,n-1){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		ans.resize(n);
		dfs(0,-1,0);
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		cout<<endl;
	}
	
	return 0;
}