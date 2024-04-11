#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int n;
long long x,y;
long long s[2000005];
long long st[2000005];
long long ans=100000000000000000LL;

int main()
{
	scanf("%d%I64d%I64d",&n,&x,&y);
	int limit=x/y;
	long long temp;
	for(int i=1;i<=n;i++)
	{
		temp=read();
		s[temp]++;
	}
	for(int i=1;i<=2000000;i++)
	{
		st[i]=st[i-1]+i*s[i];
	}
	for(int i=1;i<=2000000;i++)
	s[i]+=s[i-1];
	for(int i=2;i<=1000000;i++)
	{
		temp=0;
		for(int j=i;j<=1000000+i;j+=i)
		{
			if(limit<i)
			{
				int t=s[j]-s[j-limit-1];
				long long trans=(long long)t*j-(st[j]-st[j-limit-1]),trans2=(s[j-limit-1]-s[j-i]);
				temp+=trans*y+trans2*x;
			}
			else
			{
				temp=temp+((s[j]-s[j-i])*j-(st[j]-st[j-i]))*y;
			}
		}
		ans=min(ans,temp);
	}
	cout<<ans;
}