#include<iostream>
#include<cmath>
using namespace std;
int n,x,m,len[101],a[101][101],sum[101][101],dp1[105][105],dp2[105][10000];
int g(int k,int i,int j){
	return sum[k][len[k]]-sum[k][len[k]-j]+sum[k][i];
}
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> len[i];
		for(int j=1;j<=len[i];j++)
			cin >> x,a[i][j]=x,sum[i][j]=sum[i][j-1]+x;
	}
	for(int k=1;k<=n;k++)
		for(int l=1;l<=len[k];l++)
			for(int i=0;i<=l;i++)
				dp1[k][l]=max(dp1[k][l],g(k,i,l-i));
	for(int k=1;k<=n;k++)
		for(int i=0;i<=m;i++)
			for(int j=0;j<=min(len[k],i);j++)
				dp2[k][i]=max(dp2[k][i],dp2[k-1][i-j]+dp1[k][j]);
	cout << dp2[n][m];
	return 0;
}