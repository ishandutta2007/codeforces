#include<bits/stdc++.h>
#define N 205
using namespace std;
int n,a[N][10],b[10];
long long q[505];
double Get(int x,int y,int t)
{
	int score;
	if (x*2LL>y) score=500;
	else if (x*4LL>y) score=1000;
	else if (x*8LL>y) score=1500;
	else if (x*16LL>y) score=2000;
	else if (x*32LL>y) score=2500;
	else score=3000;
	return score*(1-t/250.);
}
double check(int x)
{
	double a1=0,a2=0;
	for (int i=1;i<=5;i++)
	{
		if (a[1][i]==-1)
		{
			if (a[2][i]!=-1)
				a2+=Get(b[i],x+n,a[2][i]);
		}
		else
		{
			if (a[2][i]==-1)
				a1+=Get(b[i],x+n,a[1][i]);
			else if (a[1][i]<a[2][i])
				a1+=Get(b[i],x+n,a[1][i]),a2+=Get(b[i],x+n,a[2][i]);
			else a1+=Get(x+b[i],x+n,a[1][i]),a2+=Get(x+b[i],x+n,a[2][i]);
		}
	}
	//cout<<a1<<' '<<a2<<endl;
	return a1-a2;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=5;j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j]!=-1) b[j]++;
		}
	}
	int ly=0;
	q[++ly]=0;
	for (int i=1;i<=5;i++)
	{
		q[++ly]=b[i]*2-n;
		q[++ly]=b[i]*4-n;
		q[++ly]=b[i]*8-n;
		q[++ly]=b[i]*16-n;
		q[++ly]=b[i]*32-n;
		//x>(n-p*b[i])/(p-1)
		q[++ly]=(n-2LL*b[i]);
		q[++ly]=(n-4LL*b[i]+2)/3;
		q[++ly]=(n-8LL*b[i]+6)/7;
		q[++ly]=(n-16LL*b[i]+14)/15;
		q[++ly]=(n-32LL*b[i]+30)/31;
	}
	int ans=1000000008;
	for (int i=1;i<=ly;i++)
	{
		if (q[i]>=0&&q[i]<=1000000007&&check(q[i])>0)
			ans=min(ans,(int)q[i]);
	}
	printf("%d\n",ans==1000000008?-1:ans);
}