#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int n,k;
vector<vector<int>> E;
vector<int> a;

vector<vector<int>> ans;

void dfs0(int cur,int p){
	ans[cur][0] = a[cur];
	rep(i,E[cur].size()){
		
		int to = E[cur][i];
		if(to==p)continue;
		
		dfs0(to,cur);
		
		auto t = ans[to];
		t.insert(t.begin(),t.back());
		t.pop_back();
		rep(j,2*k){
			ans[cur][j] ^= t[j];
		}
	}
}

void dfs1(int cur,int p,vector<int> X){
	X.insert(X.begin(),X.back());
	X.pop_back();
	rep(i,2*k){
		ans[cur][i] ^= X[i];
	}
	
	X[0] ^= a[cur];
	
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		
		vector<int> t = ans[to];
		t.insert(t.begin(),t.back());
		t.pop_back();
		rep(j,2*k)X[j] ^= t[j];
		
	}
	
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		
		vector<int> t = ans[to];
		t.insert(t.begin(),t.back());
		t.pop_back();
		rep(j,2*k)X[j] ^= t[j];
		
		dfs1(to,cur,X);
		
		rep(j,2*k)X[j] ^= t[j];
	}
	
	
}

int main(){
	
	cin>>n>>k;
	E.resize(n);
	rep(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	a.resize(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	ans.resize(n,vector<int>(2*k,0));
	
	dfs0(0,-1);
	
	vector<int> X(2*k,0);
	dfs1(0,-1,X);
	
	rep(i,n){
		if(i!=0)printf(" ");
		int temp = 0;
		for(int j=k;j<=2*k-1;j++)temp ^= ans[i][j];
		
		if(temp==0)printf("0");
		else printf("1");
		
	}
	cout<<endl;
	
    return 0;
}