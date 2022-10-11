#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int cnt,ans,cur;
int main()
{
	v.push_back(1000);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int t,s;
		scanf("%d",&t);
		if (t==1 || t==3)
		scanf("%d",&s);
		if (t==1)
		{
			cur=s;
			while (cur>v.back())
			{
				ans++;
				v.pop_back();
			}
		}
		else if (t==3)
		{
			if (cur>s)
			ans++;
			else
			v.push_back(s);
		}
		else if (t==5)
		v.push_back(1000);
		else if (t==2)
		{
			ans+=cnt;
			cnt=0;
		}
		else if (t==4)
		cnt=0;
		else
		cnt++;
	}
	printf("%d",ans);
}