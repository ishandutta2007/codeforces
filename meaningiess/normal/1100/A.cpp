#include<bits/stdc++.h>
using namespace std;
int n,k,a[150],flg[150];
int main()
{
	cin>>n>>k;int i,j,pans = -1;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		memset(flg,0,sizeof(flg));
		int tp = 0;
		for(j=i;j>=1;j-=k)flg[j] = 1;
		for(j=i;j<=n;j+=k)flg[j] = 1;
		for(j=1;j<=n;j++)if(!flg[j])tp += a[j];
		tp = abs(tp);pans = max(pans,tp);
	}
	cout<<pans;
}