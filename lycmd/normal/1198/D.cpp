#include<bits/stdc++.h>
using namespace std;
int const N=52;
int n,f[N][N][N][N];
char a[N][N];
int solve(int xl,int yl,int xr,int yr){
	if(xl==xr&&yl==yr)
		return a[xl][yl]=='#';
	if(~f[xl][yl][xr][yr])
		return f[xl][yl][xr][yr];
	int res=xr-xl==yr-yl?xr-xl+1:N;
	for(int i=xl;i<xr;i++)
		res=min(res,solve(xl,yl,i,yr)+solve(i+1,yl,xr,yr));
	for(int j=yl;j<yr;j++)
		res=min(res,solve(xl,yl,xr,j)+solve(xl,j+1,xr,yr));
	return f[xl][yl][xr][yr]=res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	memset(f,-1,sizeof f);
	cout<<solve(1,1,n,n)<<"\n";
}//