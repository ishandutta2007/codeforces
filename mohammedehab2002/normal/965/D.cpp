#include <iostream>
#include <set>
using namespace std;
int l,w,arr[100005],mn;
bool go()
{
	int cur=0,r=0;
	mn=(1<<30);
	while (cur+l<w)
	{
		int pos=-1;
		while (cur+l>r)
		{
			r++;
			if (arr[r])
			pos=r;
		}
		if (pos==-1)
		return 0;
		mn=min(mn,arr[pos]);
		cur=pos;
	}
	cur=0,r=0;
	while (cur+l<w)
	{
		int pos=-1;
		while (cur+l>r)
		{
			r++;
			if (arr[r])
			pos=r;
		}
		arr[pos]-=mn;
		cur=pos;
	}
	return 1;
}
set<int> s;
bool go2()
{
	int cur=0;
	mn=(1<<30);
	while (cur+l<w)
	{
		auto it=s.upper_bound(cur+l);
		if (it==s.begin())
		return 0;
		it--;
		if (*it<=cur)
		return 0;
		mn=min(mn,arr[*it]);
		cur=*it;
	}
	cur=0;
	while (cur+l<w)
	{
		auto it=s.upper_bound(cur+l);
		it--;
		arr[*it]-=mn;
		cur=*it;
		if (!arr[*it])
		s.erase(it);
	}
	return 1;
}
int main()
{
	scanf("%d%d",&w,&l);
	for (int i=1;i<w;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i])
		s.insert(i);
	}
	int ans=0;
	while ((l<=200 && go()) || (l>200 && go2()))
	ans+=mn;
	printf("%d",ans);
}