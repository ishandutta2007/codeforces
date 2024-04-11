#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233,M=233333;
int n,m,k,a[N],p[M],f[N][N],ans[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++)
		for(int j=1,x;j<=m;j++)
			cin>>x,a[i+j]=min(a[i+j],x);
	for(int i=2;i<=n+m;i++)
		p[a[i]]=i;
	for(int t=1;t<=n*m;t++){
		if(!p[t])continue;
		ans[p[t]]=1;
		memset(f,0,sizeof f),f[1][0]=1;
		for(int i=2;i<=n+m;i++)
			for(int j=0;j<=n+m;j++)
				f[i][j]=min(ans[i]?f[i-1][j-ans[i]]:f[i-1][j+1]+(j?f[i-1][j-1]:0),k);
		int res=f[n+m][0];
		if(res<k)
			ans[p[t]]=-1,k-=res;
	}
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<(~ans[i+j]?'(':')');
}