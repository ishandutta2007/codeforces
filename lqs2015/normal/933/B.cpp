#include<iostream>
#include<cstdio>
using namespace std;
long long p,k,cur,ans[11111111],f,nw,fk,kkk;
int main()
{
	cin>>p>>k;
	cur=p;
	f=-1;
	for (long long i=0;i<=10000000;i++)
	{
		nw=-cur/k;
		fk=cur+nw*k;
		if (fk<0) nw++;
		else if (fk>=k) nw--;
		ans[i]=nw;
		if (nw>=0 && nw<k)
		{
			f=i;
			break;
		}
		cur=nw;
	}
	if (f==-1) printf("-1\n");
	else
	{
		for (long long i=f+1;i>=0;i--)
		{
			if (!i) ans[i]=ans[i]*k+p;
			else
			{
				ans[i]=ans[i]*k+ans[i-1];
			}
		}
		kkk=f+1;
		while(!ans[kkk]) kkk--;
		printf("%I64d\n",kkk+1);
		for (int i=0;i<=kkk;i++)
		{
			if (i) printf(" %I64d",ans[i]);
			else printf("%I64d",ans[i]);
		}
	}
	return 0;
}