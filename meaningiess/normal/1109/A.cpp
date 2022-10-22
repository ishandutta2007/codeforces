#include<bits/stdc++.h>
using namespace std;
int a[300010],h[2][1100100];
int main()
{
	int n,i,t=0;long long ans=0;cin>>n;h[0][0]=1;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	{
		t^=a[i];ans+=h[i%2][t];
		h[i%2][t]++;
	}
	cout<<ans;
}