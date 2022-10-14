#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,MOD=998244353;
int t,n,sum=0,pre[N],cnt[N],ans[N];
vector<int>fac[N];
vector<array<int,3> >e[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
void dfs(int x,int fa){
	for(auto i:e[x]){
		int y=i[0],a=i[1],b=i[2];
		if(y==fa)continue;
		for(int k:fac[b])cnt[k]++;
		for(int k:fac[a])ans[k]=max(ans[k],-(--cnt[k]));
		dfs(y,x);
		for(int k:fac[a])cnt[k]++;
		for(int k:fac[b])cnt[k]--;
	}
}
void solve(int x,int fa,int val){
	sum=(sum+val)%MOD;
	for(auto i:e[x]){
		int y=i[0],a=i[1],b=i[2];
		if(y==fa)continue;
		solve(y,x,val*qpow(a,MOD-2)%MOD*b%MOD);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=2;i<N;i++)
		if(!pre[i])
			for(int j=i;j<N;j+=i)
				pre[j]=i;
	for(int i=1;i<N;i++){
		int t=i;
		while(t>1)
			fac[i].push_back(pre[t]),t/=pre[t];
	}
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cnt[i]=ans[i]=0,e[i].clear();
		for(int i=1;i<n;i++){
			int x,y,a,b;
			cin>>x>>y>>a>>b;
			e[x].push_back({y,a,b});
			e[y].push_back({x,b,a});
		}
		dfs(1,0);
		int res=1;
		for(int i=1;i<=n;i++)
			res=res*qpow(i,ans[i])%MOD;
		sum=0,solve(1,0,res);
		cout<<sum<<"\n";
	}
	return 0;
}