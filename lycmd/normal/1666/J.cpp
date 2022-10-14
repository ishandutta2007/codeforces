#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233;
int n,a[N][N],f[N][N],s[N][N],rt[N][N],fa[N];
void tomin(int l,int r,int k,int p){
	if(f[l][r]>k)
		f[l][r]=k,rt[l][r]=p;
}
void build(int l,int r){
	int k=rt[l][r];
	if(k>l)
		build(l,k-1),fa[rt[l][k-1]]=k;
	if(k<r)
		build(k+1,r),fa[rt[k+1][r]]=k;
}
int sum(int x,int y,int l,int r){
	return x>y||l>r?0:s[r][y]-s[r][x-1]-s[l-1][y]+s[l-1][x-1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j],s[i][j]=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n+1;i++)
		rt[i][i]=i,f[i][i]=f[i][i-1]=0;
	for(int d=2;d<=n;d++)
		for(int l=1;l<=n-d+1;l++){
			int r=l+d-1;
			for(int p=l;p<=r;p++)
				tomin(l,r,f[l][p-1]+f[p+1][r]+sum(1,l-1,l,p-1)+sum(r+1,n,l,p-1)
				+sum(1,l-1,p+1,r)+sum(r+1,n,p+1,r)+sum(l,r,p,p)+2*sum(l,p-1,p+1,r),p);
		}
	build(1,n);
	for(int i=1;i<=n;i++)
		cout<<fa[i]<<" ";
	cout<<"\n";
}