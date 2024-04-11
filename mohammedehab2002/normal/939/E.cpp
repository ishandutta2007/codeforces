#include <iostream>
#include <vector>
using namespace std;
vector<long double> v;
int i;
long double go(int x)
{
	return (long double)((i+v[x])/(x+1));
}
int main()
{
	long double ans=0;
	int q;
	scanf("%d",&q);
	v.push_back(0);
	while (q--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			scanf("%d",&i);
			int st=0,en=v.size()-1;
			while (st!=en)
			{
				int x=(en-st)/3;
				if (go(st+x)<go(en-x))
				en=en-x-1;
				else
				st=st+x+1;
			}
			ans=max(ans,(long double)i-go(st));
			v.push_back(v.back()+(long double)i);
		}
		else
		printf("%.10lf\n",(double)ans);
	}
}