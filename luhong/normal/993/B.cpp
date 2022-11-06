#include<iostream>
#include<cstdio>
using namespace std;
int a[20],b[20],c[20],d[20],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d%d",&a[i],&b[i]);if(a[i]>b[i])swap(a[i],b[i]);}
	for(int i=1;i<=m;i++){scanf("%d%d",&c[i],&d[i]);if(c[i]>d[i])swap(c[i],d[i]);}
	int okk=0;int ans=0;
	for(int i=1;i<=n;i++)
	{
		int ok1=0,ok2=0;
		for(int j=1;j<=m;j++)
		{
			if(c[j]==a[i]&&d[j]==b[i])continue;
			if(c[j]==a[i]||d[j]==a[i])ok1=1;
			if(d[j]==b[i]||c[j]==b[i])ok2=1;
		}
		if(ok1&&ok2)return 0*puts("-1");
		if(!ok1&&!ok2)continue;
		int k;if(ok1)k=a[i];else k=b[i];
		if(ans==0)ans=k;
		else if(ans!=k)okk=-1;
	}
	for(int i=1;i<=m;i++)
	{
		int ok1=0,ok2=0;
		for(int j=1;j<=n;j++)
		{
			if(c[i]==a[j]&&d[i]==b[j])continue;
			if(c[i]==a[j]||c[i]==b[j])ok1=1;
			if(d[i]==b[j]||d[i]==a[j])ok2=1;
		}
		if(ok1&&ok2)return 0*puts("-1");
		if(!ok1&&!ok2)continue;
		int k;if(ok1)k=c[i];else k=d[i];
		if(ans==0)ans=k;
		else if(ans!=k)okk=-1;
	}
	if(okk==-1)return 0*puts("0");
	else return 0*printf("%d\n",ans);return 0;
}