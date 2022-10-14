#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,d,a[N],pre[N][11],vis[N][11];
double v[N],f[N][11];
vector<int>ans; 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i],v[i]=log10(a[i]);
	memset(f,0xcc,sizeof f);
	memset(pre,-1,sizeof pre);
	for(int i=1;i<=n;i++){
		if(v[i]>f[i][a[i]%10])
			f[i][a[i]%10]=v[i],vis[i][a[i]%10]=1;
		for(int j=0;j<10;j++){
			if(f[i-1][j]>f[i][j])
				f[i][j]=f[i-1][j],pre[i][j]=j,vis[i][j]=0;
			int t=j*a[i]%10;
			if(f[i-1][j]+v[i]>f[i][t])
				f[i][t]=f[i-1][j]+v[i],pre[i][t]=j,vis[i][t]=1;
		}
	}
	if(f[n][d]<0.0)
		cout<<"-1\n",exit(0);
	for(int i=n;~d&&i>=1;i--){
		if(vis[i][d])
			ans.push_back(a[i]);
		d=pre[i][d];
	}
	cout<<ans.size()<<"\n";
	for(int i:ans)cout<<i<<" ";
}