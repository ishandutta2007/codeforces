#include <iostream>
#include <vector>
using namespace std;
int x,y;
bool ask(vector<int> v,int idx)
{
	if (!idx)
	return 0;
	printf("? %d",idx);
	while (v.size()!=idx)
	v.pop_back();
	for (int i:v)
	printf(" %d",i);
	printf("\n");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return (ans==y || ans==(x^y));
}
int main()
{
	int n,diff=0;
	scanf("%d%d%d",&n,&x,&y);
	vector<int> d;
	for (int i=0;i<10;i++)
	{
		vector<int> v;
		for (int x=1;x<=n;x++)
		{
			if (x&(1<<i))
			v.push_back(x);
		}
		if (ask(v,v.size()))
		{
			diff|=(1<<i);
			d=v;
		}
	}
	int st=1,en=d.size();
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (ask(d,mid))
		en=mid;
		else
		st=mid+1;
	}
	int a=d[st-1],b=(d[st-1]^diff);
	printf("! %d %d",min(a,b),max(a,b));
	fflush(stdout);
}