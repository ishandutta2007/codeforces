#include<bits/stdc++.h>
using namespace std;
int const N=55,M=40010;
int n,m,k,ans,a[N][M],s[N][M],f[N][M],pre[M],suf[M];
int sum(int x,int l,int r){
	return s[x][r]-s[x][max(l-1,0)];
}
int calc(int i,int x,int y){
	if(x>y)swap(x,y);
	return x<=y-k?sum(i,x-k+1,x)+sum(i,y-k+1,y):sum(i,x-k+1,y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],s[i][j]=s[i][j-1]+a[i][j];
	for(int i=k;i<=m;i++)
		f[1][i]=sum(1,i-k+1,i);
	for(int i=2;i<=n;i++){
		for(int x=k;x<=m;x++)
			pre[x]=max(pre[x-1],f[i-1][x]+sum(i,x-k+1,x));
		for(int x=m;x>=k;x--)
			suf[x]=max(suf[x+1],f[i-1][x]+sum(i,x-k+1,x));
		for(int y=k;y<=m;y++)
			f[i][y]=max(f[i][y],
				max(pre[y-k]+sum(i,y-k+1,y),suf[y+k]+sum(i,y-k+1,y)));
		for(int x=k;x<=m;x++){
			int l=max(k,x-k+1),r=min(m,x+k-1);
			for(int y=l;y<=x;y++)
				f[i][y]=max(f[i][y],f[i-1][x]+sum(i,y-k+1,x));
			for(int y=x+1;y<=r;y++)
				f[i][y]=max(f[i][y],f[i-1][x]+sum(i,x-k+1,y));
		}
	}
	for(int i=k;i<=m;i++)
		ans=max(ans,f[n][i]);
	cout<<ans<<"\n";
}