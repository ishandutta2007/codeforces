#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
using namespace std;
int dp[2002],n,d,t1,t2,a[2002],mmax,mmin,mpos;
long long ans;
vector<int>g[2002];
inline void dfs(int pos,int fa){
	dp[pos]=1;
	for(int i:g[pos]){
		if(i!=fa&&a[i]>=mmin&&a[i]<=mmax&&(a[i]!=mmax||i<=mpos)){
			dfs(i,pos);
			dp[pos]=1ll*dp[pos]*(dp[i]+1)%1000000007;
		}
	}
}
int main(){
	cin>>d>>n;
	F(i,1,n)scanf("%d",&a[i]);
	F(i,2,n){
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	F(i,1,n){
		mmax=a[i],mmin=a[i]-d;
		memset(dp,0,sizeof(dp));
		mpos=i;
		dfs(i,0);
		ans+=dp[i];
	}
	cout<<ans%1000000007;
	return 0;
}