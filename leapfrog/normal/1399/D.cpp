#include<bits/stdc++.h>
using namespace std;
int t,cnt,n,a[200005],res[200005];char c[200005];deque<int>s0,s1;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%s",&n,c+1),s0.clear(),s1.clear(),cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]=='0')
			{
				if(s1.empty()) res[i]=++cnt,s0.push_back(cnt);
				else res[i]=s1.front(),s0.push_back(s1.front()),s1.pop_front();
			}
			if(c[i]=='1')
			{
				if(s0.empty()) res[i]=++cnt,s1.push_back(cnt);
				else res[i]=s0.front(),s1.push_back(s0.front()),s0.pop_front();
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=n;i++) printf("%d%c",res[i],i==n?'\n':' ');
	}
	return 0;
}