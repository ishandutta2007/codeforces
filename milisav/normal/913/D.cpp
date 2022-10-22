#include <bits/stdc++.h>
using namespace std;
int n,t;
pair<int,pair<int,int> > a[300000];
int bit[200000];
bool pos(int m)
{
	int d=0;
	int b=0;
	vector<int> v;
	for(int i=0;i<n && b<m;i++)
	{
		if(a[i].second.first>=m)
		{
			d+=a[i].first;
			b++;
		}
	}
	return (b==m && d<=t);
}
void sol(int m)
{
	int d=0;
	int b=0;
	vector<int> v;
	for(int i=0;i<n && b<m;i++)
	{
		if(a[i].second.first>=m)
		{
			printf("%d ",a[i].second.second);
			b++;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&t);
	int x,y;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		a[i]=make_pair(y,make_pair(x,i+1));
	}
	sort(a,a+n);
	int l=0;
	int r=n;
	int m;
	while(l<r)
	{
		m=(l+r+1)>>1;
		if(pos(m)) l=m;
		else r=m-1;
	}
	printf("%d\n",l);
	printf("%d\n",l);
	sol(l);
	return 0;
}