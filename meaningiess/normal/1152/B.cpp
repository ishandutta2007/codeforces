#include<bits/stdc++.h>
using namespace std;
int ans[44],er[44];
int main()
{
	int n,m=0,i,j;cin>>n;if (n%2==0) ans[++m]=0;
	int t=n,r=0;while (t) er[++r]=t%2,t/=2;
	for (i=r;i;i--) if (!er[i])
	{
		ans[++m]=i;
		for (j=i;j;j--) er[j]^=1;er[1]=1;
	}cout<<m*2<<endl;
	for (i=1;i<=m;i++) cout<<ans[i]<<' ';
}