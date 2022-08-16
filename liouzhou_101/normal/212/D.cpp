#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1<<20;

int n;
int v[MaxN],L[MaxN],R[MaxN];
int top,Q[MaxN];
long long s[MaxN],t[MaxN];
double p[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&v[i]);
	for (int i=n;i>=1;--i)
	{
		while (top&&v[Q[top]]>v[i]) --top;
		R[i]=(top)?Q[top]-1:n;
		Q[++top]=i;
	}
	top=0;
	for (int i=1;i<=n;++i)
	{
		while (top&&v[Q[top]]>=v[i]) --top;
		L[i]=(top)?Q[top]+1:1;
		Q[++top]=i;
	}
	for (int i=1;i<=n;++i)
	{
		s[1]+=(long long)v[i]*(i-L[i]+1);
		s[R[i]-L[i]+2]-=(long long)v[i]*(i-L[i]+1);
		s[1]-=(long long)v[i]*(i-L[i]+1);
		s[i-L[i]+2]+=(long long)v[i]*(i-L[i]+1);
		t[1]+=v[i];
		t[i-L[i]+2]-=v[i];
		s[R[i]-i+1]+=(long long)v[i]*(R[i]-i+1);
		s[R[i]-L[i]+2]-=(long long)v[i]*(R[i]-i+1);
		t[R[i]-i+1]-=v[i];
		t[R[i]-L[i]+2]+=v[i];
	}
	for (int i=1;i<=n;++i)
	{
		s[i]+=s[i-1];
		t[i]+=t[i-1];
		p[i]=(s[i]+i*t[i])/(double)(n-i+1);
	}
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int x;
		scanf("%d",&x);
		printf("%.15lf\n",p[x]);
	}
}

int main()
{
	init();
	work();
	return 0;
}