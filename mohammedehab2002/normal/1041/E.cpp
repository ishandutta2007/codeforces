#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v;
int cnt[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		cnt[a]++;
		if (b!=n)
		{
			printf("NO");
			return 0;
		}
	}
	int cur=n-1;
	for (int i=n-1;i>0;i--)
	{
		if (!cnt[i])
		continue;
		int tmp=n;
		while (cnt[i]>1)
		{
			while (cnt[cur])
			cur--;
			if (cur>i)
			{
				printf("NO");
				return 0;
			}
			v.push_back({tmp,cur});
			tmp=cur;
			cnt[i]--;
			cur--;
		}
		v.push_back({tmp,i});
	}
	printf("YES\n");
	for (auto p:v)
	printf("%d %d\n",p.first,p.second);
}