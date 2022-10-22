#include<iostream>
using namespace std;
int h[100010];
int main()
{
	int n,m,i,j,t,s=0;cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>t;
		if (h[t]>0) s--;h[t]++;s++;
		if (s==n) {cout<<1;for (j=1;j<=n;j++) {h[j]--;if (!h[j]) s--;}}
		else cout<<0;
	}
}