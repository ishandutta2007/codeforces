#include<bits/stdc++.h>
using namespace std;
int n,k,t,s=0,a[200006],w[200005],x[200005],y[200005];
int main()
{
	cin>>n>>t>>k;
	if(k>n-t)puts("-1"),exit(0);w[0]=1;
	for(int i=1;i<=t;i++)scanf("%d",&a[i]),s+=max(0,a[i-1]-a[i]),w[i]=w[i-1]+a[i];s+=a[t];
	if(k<s)puts("-1"),exit(0);cout<<n<<endl;
	k=k-s;for(int i=2;i<=w[1];i++)printf("1 %d\n",i);
	for(int i=2;i<=t;i++)
	{
		printf("%d %d\n",w[i-2]+1,w[i-1]+1);x[i]=1,y[i]=1;
		while(a[i]>a[i-1]+x[i]-1)
		{
			x[i]++;
			printf("%d %d\n",w[i-2]+1,w[i-1]+x[i]);
		}
	}
	for(int i=2;i<=t;i++)
	{
		while(k>0&&x[i]<a[i])
		{
			k--;x[i]++;
			printf("%d %d\n",w[i-2]+y[i],w[i-1]+x[i]);
		}
		while(x[i]<a[i])
		{
			x[i]++,y[i]++;
			printf("%d %d\n",w[i-2]+y[i],w[i-1]+x[i]);
		}
	}
	return 0;
}