#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int cnt=0,cur=a;
		while (cur<100005)
		{
			v[cur].push_back(cnt);
			cnt++;
			cur<<=1;
		}
		cnt=0;
		while (a)
		{
			bool b=(a&1);
			a>>=1;
			cnt++;
			v[a].push_back(cnt);
			if (b && a)
			{
				int tmp=a,cnt2=cnt;
				while ((tmp<<1)<100005)
				{
					cnt2++;
					tmp<<=1;
					v[tmp].push_back(cnt2);
				}
			}
		}
	}
	int ans=(1<<30);
	for (int i=0;i<100005;i++)
	{
		if (v[i].size()==n)
		{
			int cur=0;
			for (int x:v[i])
			cur+=x;
			ans=min(ans,cur);
		}
	}
	printf("%d",ans);
}