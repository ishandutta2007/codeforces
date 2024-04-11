#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

int ans = 0;
int N,K;
 
void dfs(vector<int> &dp,vector<vector<int>> &E,int now,int p){
	for(int i=0;i<E[now].size();i++){
		dfs(dp,E,E[now][i],now);
		dp[now] = max(dp[now],dp[E[now][i]]+1);
	}
	if(dp[now]==K-1&&p!=0&&now!=0){
		dp[now] = -1;
		ans++;
	}
}

int solve(int nn,int kk,vector<int> b){
	ans = 0;
	N = b.size();
	K = kk;
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<N;i++){
		int a = b[i];
		if(i==0){
			if(a!=0)ans++;
		}
		else{
			E[a].push_back(i);
		}
	}
 
	vector<int> dp(N,0);
	dfs(dp,E,0,-1);
 
	return ans;
}


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,k;
		scanf("%d %d",&n,&k);
		vector<int> p(n,0);
		rep(i,n-1){
			scanf("%d",&p[i+1]);
			p[i+1]--;
		}
		int ok = n+1,ng = 0;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(solve(n,mid,p)<=k)ok = mid;
			else ng=  mid;
		}
		printf("%d\n",ok);
	}
	
	return 0;
}