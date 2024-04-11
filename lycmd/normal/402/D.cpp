#include<bits/stdc++.h>
using namespace std;
int const N=5010,M=100010;
int n,m,tot,ans,a[N],g[N],pr[M],vis[M];
set<int>b;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int calc(int x){
	int res=0;
	for(int i=1;pr[i]*pr[i]<=x;i++)
		while(x%pr[i]==0)
			res+=b.count(pr[i])?-1:1,x/=pr[i];
	if(x>1)
		res+=b.count(x)?-1:1;
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	for(int i=2;i<M;i++)
		if(!vis[i]){
			pr[++tot]=i;
			for(int j=i;j<M;j+=i)
				vis[j]=1;
		}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],g[i]=gcd(g[i-1],a[i]);
	for(int i=1,x;i<=m;i++)
		cin>>x,b.insert(x);
	for(int i=n;i>=1;i--){
		int t=calc(g[i]);
		if(t<=0)
			for(int j=1;j<=i;j++)
				a[j]/=g[i],g[j]/=g[i];
	}
	for(int i=1;i<=n;i++)
		ans+=calc(a[i]);
	cout<<ans<<"\n";
}