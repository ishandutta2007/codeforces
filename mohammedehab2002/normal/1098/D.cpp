#include <iostream>
#include <set>
using namespace std;
multiset<int> s[35];
long long sum[35];
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		char c;
		int a,ans=0;
		getchar();
		scanf("%c%d",&c,&a);
		int i=0;
		while ((1<<i)<=a)
		i++;
		i--;
		if (c=='+')
		{
			s[i].insert(a);
			sum[i]+=a;
		}
		else
		{
			s[i].erase(s[i].find(a));
			sum[i]-=a;
		}
		long long tmp=0;
		for (int i=0;i<=30;i++)
		{
			ans+=s[i].size();
			if (!s[i].empty() && *s[i].begin()>2*tmp)
			ans--;
			tmp+=sum[i];
		}
		printf("%d\n",ans);
	}
}