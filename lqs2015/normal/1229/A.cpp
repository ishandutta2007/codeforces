#include<bits/stdc++.h>
using namespace std;
int n,cnt,pre,pos;
long long ans;
pair<long long,int> a[7777];
vector<long long> v;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].first);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].second);
	}
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	pre=1;
	while(pre<=n)
	{
		pos=pre;
		while(pos<=n && a[pos].first==a[pre].first) pos++;
		if (pre<pos-1)
		{
			for (int i=pre;i<pos;i++) ans+=a[i].second;
			v.push_back(a[pre].first);
		}
		else
		{
			bool f=0;
			for (int i=0;i<v.size();i++)
			{
				if ((v[i]&a[pre].first)==a[pre].first) 
				{
					f=1;
					break;
				}
			}
			if (f)
			{
				v.push_back(a[pre].first);
				ans+=a[pre].second;
			}
		}
		pre=pos;
	}
	printf("%lld\n",ans);
	return 0;
}