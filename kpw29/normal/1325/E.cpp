#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1,I=1e9;
int n,a[N],t,q[N],c,d[N],p[N],s,x,A=I;
vector<int>g[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t=0,q[2]=1;
		for(int j=2;j*j<=a[i];j++)
		{
			c=0;
			while(a[i]%j==0)
				a[i]/=j,c++;
			if(c&1)
				q[++t]=j;
		}
		if(a[i]>1)
			q[++t]=a[i];
		if(t==0)
			A=1;
		g[q[1]].push_back(q[2]),g[q[2]].push_back(q[1]);
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<N;j++)
			d[j]=I;
		d[i]=0,s=t=0,q[++t]=i;
		while(s<t)
		{
			x=q[++s];
			for(int j=0;j<g[x].size();j++)
				if(g[x][j]!=p[x])
				{
					if(d[g[x][j]]==I)
						d[g[x][j]]=d[x]+1,p[g[x][j]]=x,q[++t]=g[x][j];
					else
						A=min(A,d[x]+d[g[x][j]]+1);
				}
		}
	}
	if(A==I)
		cout<<-1;
	else
		cout<<A;
	return 0;
}