#include<bits/stdc++.h>
using namespace std;
int const N=505;
int n,m,k,s[N][N];
long long ans;
char a[N][N];
int sum(int ax,int ay,int bx,int by){
	return s[bx][by]-s[ax-1][by]-s[bx][ay-1]+s[ax-1][ay-1];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++)
			s[i][j]=(a[i][j]&1&&a[i-1][j]&1&&a[i][j-1]&1&&a[i+1][j]&1
				&&a[i][j+1]&1)+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int l=2;l<n;l++)
		for(int r=l;r<n;r++)
			for(int i=2,j=2;i<m;i++){
				while(j<m&&sum(l,i,r,j)<k)j++;
				if(j==m)break;
				ans+=m-j;
			}
	cout<<ans<<"\n";
}