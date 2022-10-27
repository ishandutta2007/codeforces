// LUOGU_RID: 90648717
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int p=1e9+7;
int qp(int x,int n=p-2)
{
	int res=1;
	while(n)
	{
		if(n&1)res=res*x%p;
		x=x*x%p,n>>=1;
	}
	return res;
}
int e[101][101];
int b[101][101];
int a[101][101],n;
int mattree(int g){
	memset(a,0,sizeof(a));
	for(int x=1;x<=n;x++)
	for(int y=1;y<=n;y++)
	if(x!=y)(a[x][y]-=e[x][y]*(g-1)+1)%=p,(a[x][x]+=e[x][y]*(g-1)+1)%=p;
	int res=1;
	for(int x=1;x<n;x++)
	{
		int inv=qp(a[x][x]);
		for(int y=x+1;y<n;y++)
		{
			int qwq=a[y][x]*inv%p;
			for(int z=x;z<=n;z++)
			(a[y][z]-=a[x][z]*qwq%p)%=p;
		}
		(res*=a[x][x])%=p;
	}
	return (res+p)%p;
}
main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
	cin>>n;
	for(int x=1;x<n;x++)
	{
		int u,v;
		cin>>u>>v;
		e[u][v]=e[v][u]=1;
	}
	for(int x=0;x<n;x++)
	{
		b[x][0]=1,b[x][n]=mattree(x+1);
		int qwq=1;
		for(int y=1;y<n;y++)
		(qwq*=x+1)%=p,b[x][y]=qwq;
	}
	for(int x=0;x<n;x++)
	{
		int inv=qp(b[x][x]);
		for(int y=0;y<n;y++)
		if(x!=y)
		{
			int qwq=b[y][x]*inv%p;
			for(int z=x+1;z<=n;z++)
			(b[y][z]-=b[x][z]*qwq%p)%=p;
		}
	}
	int ans=0;
	//for(int x=n-1;x>=n-k-1;x--)
	for(int x=0;x<n;x++)
	cout<<(b[x][n]*qp(b[x][x])%p+p)%p<<' ';
	//(ans+=b[x][n]*qp(b[x][x])%p)%=p;
	//cout<<(ans+p)%p<<endl;
}