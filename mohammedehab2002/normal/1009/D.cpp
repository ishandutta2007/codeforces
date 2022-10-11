#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<pair<int,int> > v;
void add(int a,int b)
{
	if (v.size()!=m)
	v.push_back({a,b});
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	v.push_back({i,i+1});
	if (v.size()>m)
	{
		printf("Impossible");
		return 0;
	}
	n=min(n,600);
	for (int i=1;i<=n;i++)
	{
		for (int x=i+2;x<=n;x++)
		{
			if (__gcd(i,x)==1)
			add(i,x);
		}
	}
	if (v.size()!=m)
	{
		printf("Impossible");
		return 0;
	}
	printf("Possible\n");
	for (auto p:v)
	printf("%d %d\n",p.first,p.second);
}