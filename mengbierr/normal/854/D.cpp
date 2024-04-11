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
struct data
{
	int cost;
	int pla;
	int tim;
}come[100005],leave[100005];
int tot1,tot2,val[100005],finish_time,cou,val2[100005],cou2,finish_time2;long long sum,finish[1000005],sum2,ans=900000000000000000LL;
bool cmp(data x,data y)
{
	return x.tim<y.tim;
}
bool cmp2(data x,data y)
{
	return x.tim>y.tim;
}
int main()
{
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int d=read(),f=read(),t=read(),c=read();
		if(f==0)
		{
			leave[++tot1].pla=t;
			leave[tot1].cost=c;
			leave[tot1].tim=d;
		}
		else if(t==0)
		{
			come[++tot2].pla=f;
			come[tot2].cost=c;
			come[tot2].tim=d;
		}
	}
	sort(come+1,come+tot2+1,cmp);
	sort(leave+1,leave+tot1+1,cmp2);
	for(int i=1;i<=tot2;i++)
	{
		if(!val[come[i].pla])
		{
			val[come[i].pla]=come[i].cost;
			sum+=come[i].cost;
			cou++;
			if(cou==n)
			{
				finish_time=come[i].tim;
				finish[come[i].tim]=sum;
			}
		}
		else
		{
			if(come[i].cost>=val[come[i].pla])
			continue;
			sum+=come[i].cost;
			sum-=val[come[i].pla];
			val[come[i].pla]=come[i].cost;
			if(cou==n)
			{
				finish[come[i].tim]=sum;
			}
		}
	}
	for(int i=finish_time;i<=1000000;i++)
	{
		if(finish[i]==0)
		finish[i]=finish[i-1];
	}
	//for(int i=1;i<=20;i++)
//	cout<<finish[i]<<" ";
	for(int i=1;i<=tot1;i++)
	{
		if(finish_time+k+1>leave[i].tim)
		break;
		if(!val2[leave[i].pla])
		{
			cou2++;
			val2[leave[i].pla]=leave[i].cost;
			sum2+=leave[i].cost;
			if(cou2==n&&finish_time+k<=leave[i].tim)
			{
				ans=min(ans,sum2+finish[leave[i].tim-k-1]);
			}
		}
		else
		{
			if(leave[i].cost>=val2[leave[i].pla])
			continue;
			sum2+=leave[i].cost;
			sum2-=val2[leave[i].pla];
			val2[leave[i].pla]=leave[i].cost;
			if(cou2==n)
			{
				ans=min(ans,sum2+finish[leave[i].tim-k-1]);
			}
		}
	}
	if(ans==900000000000000000LL||!finish_time||cou2!=n||cou!=n)
	puts("-1");
	else cout<<ans;
}