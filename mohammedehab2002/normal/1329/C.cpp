#include <bits/stdc++.h>
using namespace std;
int h,g,a[(1<<21)],dep[(1<<21)];
vector<int> ans,tmp;
bool test(int i)
{
	tmp.push_back(a[i]);
	if (!a[i])
	return (dep[i]>g);
	bool ret=0;
	if (a[2*i]>a[2*i+1])
	{
		if (test(2*i))
		{
			a[i]=tmp.back();
			ret=1;
		}
	}
	else
	{
		if (test(2*i+1))
		{
			a[i]=tmp.back();
			ret=1;
		}
	}
	tmp.pop_back();
	return ret;
}
int main()
{
	for (int i=2;i<(1<<21);i++)
	dep[i]=dep[i/2]+1;
	int t;
	scanf("%d",&t);
	while (t--)
	{
		ans.clear();
		scanf("%d%d",&h,&g);
		for (int i=1;i<(1<<h);i++)
		scanf("%d",&a[i]);
		for (int i=(1<<h);i<(1<<(h+1));i++)
		a[i]=0;
		long long sum=0;
		for (int i=1;i<(1<<g);i++)
		{
			if (test(i))
			{
				ans.push_back(i);
				i--;
			}
			else
			sum+=a[i];
			tmp.pop_back();
		}
		printf("%I64d\n",sum);
		for (int i:ans)
		printf("%d ",i);
		printf("\n");
	}
}