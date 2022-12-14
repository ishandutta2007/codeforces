#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
set<pair<pair<int,int>,int> >  s;
int n,mx;
pair<pair<int,int>,int> a[222222];
pair<int,int> ccur;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first.first,&a[i].first.second);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	mx=-1e9;
	for (int i=1;i<=n;i++)
	{
		ccur=make_pair(max(mx,a[i].first.first-1),a[i].first.second);
		if (ccur.second<=mx)
		{
			cout<<a[i].second<<endl;
			return 0;
		}
		mx=max(mx,a[i].first.second);
		while(!s.empty() && a[i].first.first>s.begin()->first.first+1) s.erase(s.begin());
		if (!s.empty() && mx>=s.begin()->first.second)
		{
			printf("%d\n",s.begin()->second);
			return 0;
		}
		if (!s.empty() && s.begin()->first.first<mx)
		{
			pair<pair<int,int>,int> cur=*s.begin();
			cur.first.first=mx;
			s.erase(s.begin()); 
			while(!s.empty() && s.begin()->first.first<=mx) s.erase(s.begin());
			s.insert(cur);
		}
		set<pair<pair<int,int>,int> >::iterator it=s.lower_bound(make_pair(ccur,0));
		if (it!=s.end())
		{
			if (ccur.second>=it->first.second) continue;
		}
		if (it!=s.begin())
		{
			it--;
			while(ccur.second<=it->first.second)
			{
				s.erase(it);
				if (it==s.begin()) break;
				it--;
			}
		}
		s.insert(make_pair(ccur,a[i].second));
	}
	printf("-1\n");
	return 0;
}