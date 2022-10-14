#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,m,a[N],cnt[N],f[N][3][3];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	memset(f,0xcc,sizeof f),f[0][0][0]=0;
	for(int i=1;i<=m;i++)
		for(int x=0;x<3;x++)
			for(int y=0;y<3;y++)
				for(int z=0;z<=min(2,cnt[i]-x-y);z++)
					f[i][y][z]=max(f[i][y][z],f[i-1][x][y]+z+(cnt[i]-x-y-z)/3);
	cout<<f[m][0][0]<<"\n";
}