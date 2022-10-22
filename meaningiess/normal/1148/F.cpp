#include<bits/stdc++.h>
#define ll long long 
#define N 300010
using namespace std;
ll a[N],w[N];
int main()
{
	int n,i,j;ll s=0,ans=0;cin>>n;
	for (i=1;i<=n;i++) cin>>w[i]>>a[i],s+=w[i];
	for (i=1;s>0 && i<=n;i++) w[i]*=-1;
	for (j=0;j<62;j++)
	{
		for (s=0,i=1;i<=n;i++) s+=((a[i]>>j)==1)*w[i];
		if (s<0) for (ans|=1ll<<j,i=1;i<=n;i++) w[i]*=-(a[i]>>j&1)*2+1;
	}
	cout<<ans;
}