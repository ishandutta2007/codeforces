#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
bool ok[100005];
int main()
{
	int n=read();int ans=0;
	for(int i=0;i<=99999;i++)
	{
		if(n-i>=0)
		{
			int temp=n-i,sum=temp;
			while(temp)
			{
				sum+=temp%10;
				temp/=10;
			}
			if(sum==n)
			{
				ans++;
				ok[i]=1;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=99999;i>=0;i--)
	{
		if(ok[i])
		{
			printf("%d\n",n-i);
		}
	}
}