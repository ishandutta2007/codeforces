#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<long long,long long> > v;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	long long st=(1LL<<(n-1)),en=(1LL<<n)-1;
	while (q--)
	{
		int i,a;
		long long l,r;
		scanf("%d%I64d%I64d%d",&i,&l,&r,&a);
		l<<=(n-i);
		r<<=(n-i);
		r|=(1LL<<(n-i))-1;
		if (a)
		{
			st=max(st,l);
			en=min(en,r);
		}
		else
		{
			v.push_back({l,0});
			v.push_back({r+1,1});
		}
	}
	if (st>en)
	{
		printf("Game cheated!");
		return 0;
	}
	v.push_back({st-1,0});
	v.push_back({st,1});
	v.push_back({en+1,-1});
	sort(v.begin(),v.end());
	long long ans=-1;
	int cnt=0;
	for (int i=0;i<v.size();i++)
	{
		if (!cnt && ans!=-1 && v[i].first!=ans+1)
		{
			printf("Data not sufficient!");
			return 0;
		}
		if (v[i].second==-1)
		break;
		if (v[i].second)
		{
			cnt--;
			if (!cnt)
			{
				if (v[i].first<st)
				continue;
				if (ans!=-1)
				{
					printf("Data not sufficient!");
					return 0;
				}
				else
				ans=v[i].first;
			}
		}
		else
		cnt++;
	}
	if (ans==-1)
	printf("Game cheated!");
	else
	printf("%I64d",ans);
}