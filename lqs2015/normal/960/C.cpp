#include<iostream>
#include<cstdio>
using namespace std;
long long ans[11111],cnt,x,d,pos,kp,len;
int main()
{
	cin>>x>>d;
	pos=1;
	while(x)
	{
		for (long long i=30;i>=1;i--)
		{
			if ((1<<i)-1<=x)
			{
				kp=(1<<i)-1;
				len=i;
				break;
			}
		}
		for (long long j=1;j<=len;j++)
		{
			ans[++cnt]=pos;
		}
		pos=pos+d+1;
		x-=kp;
	}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}