#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1<<17;

int F[7][MaxN];
int mod[7];

int n;

long long v[7][11][MaxN<<1];

void add(int k,int L,int R,int x,long long p)
{
	if (L==R)
	{
		for (int i=2;i<=6;++i)
			for (int j=1;j<=mod[i];++j)
				v[i][j][k]=p*F[i][j];
		return;
	}
	int mid=(L+R)>>1;
	if (x<=mid)
		add(k<<1,L,mid,x,p);
	else
		add(k<<1|1,mid+1,R,x,p);
	for (int i=2;i<=6;++i)
		for (int j=1;j<=mod[i];++j)
		{
			int t=(j+(R-L+1)/2)%mod[i];
			if (!t) t=mod[i];
			v[i][j][k]=v[i][j][k<<1]+v[i][t][k<<1|1];
		}
}

long long get(int k,int L,int R,int x,int y,int z,int t)
{
	if (L==x&&R==y)
		return v[z][t][k];
	int mid=(L+R)>>1;
	if (y<=mid)
		return get(k<<1,L,mid,x,y,z,t);
	if (x>mid)
		return get(k<<1|1,mid+1,R,x,y,z,t);
	int u=(t+mid-x+1)%mod[z];
	if (!u) u=mod[z];
	return get(k<<1,L,mid,x,mid,z,t)+get(k<<1|1,mid+1,R,mid+1,y,z,u);
}

void init()
{
	for (int i=2;i<=6;++i)
	{
		mod[i]=2*(i-1);
		for (int j=1;j<=100000;++j)
		{
			int t=j%(2*(i-1));
			if (!t)
				F[i][j]=2;
			else if (t<=i)
				F[i][j]=t;
			else
				F[i][j]=2*i-t;
		}
	}
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		add(1,1,MaxN,i,x);
	}
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int flag;
		scanf("%d",&flag);
		if (flag==1)
		{
			int x,p;
			scanf("%d%d",&x,&p);
			add(1,1,MaxN,x,p);
		}
		else
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			printf("%I64d\n",get(1,1,MaxN,x,y,z,1));
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}