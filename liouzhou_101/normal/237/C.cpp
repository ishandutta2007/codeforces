#include<cstdio>
#include<iostream>

using namespace std;

int u[1000010];

int main()
{
	u[1]=1;
	for (int i=2;i<=1000000;++i)
		if (!u[i])
			for (int j=2;i*j<=1000000;++j)
				u[i*j]=1;
	for (int i=1;i<=1000000;++i)
	{
		u[i]^=1;
		u[i]+=u[i-1];
	}
	int a,b,k;
	cin>>a>>b>>k;
	if (u[b]-u[a-1]<k)
	{
		puts("-1");
		return 0;
	}
	int L=1,R=b-a+1,get=b-a+1;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		int flag=0;
		for (int i=a;i<=b-mid+1;++i)
			if (u[i+mid-1]-u[i-1]<k)
			{
				flag=1;
				break;
			}
		if (!flag)
		{
			get=mid;
			R=mid-1;
		}
		else
			L=mid+1;
	}
	cout<<get<<endl;
	return 0;
}