#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int pri[50100],tot=0;bool is[50100];
void init()
{
    for(int i=2;i<=50000;i++)
    {
        if(!is[i])pri[++tot]=i;
        for(int j=1;j<=tot&&i*pri[j]<=50000;j++)
        {
            is[i*pri[j]]=1;
            if(i%pri[j]==0){break;}
        }
    }
}
int a[201000],b[201000],o[200000],len=0;int n;
int solve(int x)
{
	len=0;
	int y=x;
	for(int i=1;i<=tot;i++)
	{
		bool ok=0;
		while(y%pri[i]==0)
		{
			y/=pri[i];ok=1;
		}
		if(ok)o[++len]=pri[i];
	}
	if(y!=1)o[++len]=y;
	for(int k=1;k<=len;k++)
	{
		bool ok=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]%o[k]!=0&&b[i]%o[k]!=0){ok=1;break;}
		}
		if(!ok)return o[k];
	}
	return -1;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	int ans1=solve(a[1]),ans2=solve(b[1]);
	if(ans1!=-1)printf("%d\n",ans1);
	else if(ans2!=-1)printf("%d\n",ans2);
	else puts("-1");
	return 0;
}