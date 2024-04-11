#include <bits\stdc++.h>
using namespace std;
int n;
int m;
int c[5];
int d[5];
int u,v;
int a[500000];
vector<int> b[500000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) a[i]=a[i]+2;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		b[u].push_back(v);
		b[v].push_back(u);
	}
	m=a[0];
	for(int i=1;i<n;i++) if(a[i]>m) m=a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]==m) c[0]++;
		if(a[i]+1==m) c[1]++;
		if(a[i]+2==m) c[2]++;
	}
	int r=m;
	for(int i=0;i<n;i++)
	{
		d[0]=c[0];
		d[1]=c[1];
		d[2]=c[2];
		if(a[i]==m)
		{
			d[0]--;
			d[2]++;
		} 
		if(a[i]+1==m) d[1]--;
		for(int j=0;j<b[i].size();j++)
		{
			if(a[b[i][j]]==m)
			{
				d[0]--;
				d[1]++;
			}
			if(a[b[i][j]]+1==m)
			{
				d[1]--;
				d[2]++;
			}
		}
		if(d[0]==0)
		{
			if(d[1]==0) r=m-2;
			else
			{
				if(r==m) r=m-1;
			}
		}
	}
	printf("%d",r);
	return 0;
}