#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[100007];
vector<int> b[100007];
int n,m;
int k;
int d[100007];
int l,r;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&k);
			a[i].push_back(k);
		}
	}
	scanf("%d",&k);
	for(int j=0;j<m;j++) b[0].push_back(1);
	int f;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			f=a[i-1][j];
			f=b[i-1][j];
			if(a[i][j]>=a[i-1][j]) f++;
			else f=1;
			b[i].push_back(f); 
		}
	}
	for(int i=0;i<n;i++)
	{
		f=b[i][0];
		for(int j=1;j<m;j++)
		{
			if(b[i][j]>f) f=b[i][j];
		}
		d[i]=f;
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&l,&r);
		if(d[r-1]>r-l) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}