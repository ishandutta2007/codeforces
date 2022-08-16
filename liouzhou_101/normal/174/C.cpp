#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=100010;

int n,ans,top;
int v[MaxN],Q[MaxN],p[MaxN],L[MaxN],R[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&v[i]);
}

void work()
{
	top=0;
	for (int i=1;i<=n+1;++i)
	{
		while (top)
		{
			if (Q[top]<=v[i]) break;
			++ans;
			L[ans]=p[top];
			R[ans]=i;
			--top;
		}
		for (int x=Q[top]+1;x<=v[i];++x)
		{
			++top;
			Q[top]=x;
			p[top]=i;
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=ans;++i)
		printf("%d %d\n",L[i],R[i]-1);
}

int main()
{
	init();
	work();
	return 0;
}