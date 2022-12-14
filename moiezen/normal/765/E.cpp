#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define N 200005
int n,x,y,f1;
std::vector<int> e[N];
int pre[N],dp[N],dp1,ans,no_,no_2;
void dfs(int x){
	dp[x]=0;
	rpt(i,0,e[x].size()-1){
		int y=e[x][i];
		if(y==pre[x]) continue;
		pre[y]=x;dfs(y);
		if(!dp[x]) dp[x]=dp[y]+1;
		else if(dp[x]!=dp[y]+1){
			if(x!=no_) if(f1) f1=0,no_2=x;
			if(x==no_){
				if(!dp1) dp1=dp[y]+1;
				else if(dp1!=dp[y]+1) if(f1) f1=0,no_2=x;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	rpt(i,1,n-1){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);e[y].push_back(x);
	}
	f1=1;dp1=0;
	no_=1;pre[1]=0;dfs(1);
	if(!f1){
		f1=1;dp1=0;
		no_=no_2;pre[no_]=0;dfs(no_);
	}
	ans=dp[no_]+dp1;
	while(!(ans&1)) ans>>=1;
	if(f1) printf("%d",ans);else printf("-1");
}