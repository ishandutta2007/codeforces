#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[222222],ql[222222],qr[222222],he[444444],ne[444444],c[1111111],res[222222];
int cd=555;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	int cnt=(n+cd-1)/cd;
	for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&ql[i],&qr[i]);
		ql[i]--;qr[i]--;
		int j=ql[i]/cd*cnt+qr[i]/cd;
		ne[i]=he[j];
		he[j]=i;
	}
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		ans=ans+a[i]*(2*c[a[i]]+1);
		++c[a[i]];
	}
	int cl=0,cr=n-1;
	for (int i=0;i<cnt*cnt;i++)
	{
		for (int j=he[i];j>0;j=ne[j])
		{
			while(cl>ql[j])
			{
				cl--;
				ans=ans+a[cl]*(2*c[a[cl]]+1);
				c[a[cl]]++;
			}
			while(cl<ql[j])
			{
				c[a[cl]]--;
				ans=ans-a[cl]*(2*c[a[cl]]+1);
				cl++;
			}
			while(cr>qr[j])
			{
				c[a[cr]]--;
				ans=ans-a[cr]*(2*c[a[cr]]+1);
				cr--;
			}
			while(cr<qr[j])
			{
				cr++;
				ans=ans+a[cr]*(2*c[a[cr]]+1);
				c[a[cr]]++;
			}
			res[j]=ans;
		}
	}
	for (int i=1;i<=m;i++) printf("%I64d\n",res[i]);
	return 0;
}