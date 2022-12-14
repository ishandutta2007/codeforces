#include<iostream>
#include<cstdio>
using namespace std;
int n,k,num,cnt,ans,a[111111],pos,mx;
int main()
{
	scanf("%d%d",&n,&k);
	mx=1;
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&num);
		for (int j=1;j<=num;j++) scanf("%d",&a[j]);
		if (a[1]!=1) continue;
		cnt=1;
		for (int i=2;i<=num;i++) 
		{
			if (a[i]!=a[i-1]+1) break;
			cnt++;
		}
		mx=max(mx,cnt);
	}
	cout<<n-mx+1-k+n-mx<<endl;
	return 0;
}