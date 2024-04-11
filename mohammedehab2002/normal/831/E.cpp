#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
pair<int,int> arr[100005];
int gr[100005],d[100005],cnt[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i].first),arr[i].second=i;
	sort(arr,arr+n);
	for (int i=0;i<n;)
	{
		deque<int> de;
		for (int x=i;x<n && arr[x].first==arr[i].first;x++)
		de.push_back(arr[x].second);
		if (!i)
		{
			i+=de.size();
			continue;
		}
		int op=de.size();
		while (op-- && de.front()<arr[i-1].second)
		{
			de.push_back(de.front());
			de.pop_front();
		}
		for (int x=i;x<i+de.size();x++)
		arr[x].second=de[x-i];
		i+=de.size();
	}
	for (int i=0;i<n;i++)
	d[arr[i].second]=i;
	memset(gr,-1,sizeof(gr));
	int c=0;
	for (int i=0;i<n;i++)
	{
		if (!d[i])
		gr[i]=c++;
		else if (gr[arr[d[i]-1].second]!=-1)
		gr[i]=gr[arr[d[i]-1].second];
		else
		gr[i]=c++;
		cnt[gr[i]]++;
	}
	long long ans=0;
	int cur=0,sz=n;
	while (sz)
	{
		ans+=sz;
		sz-=cnt[gr[arr[cur].second]];
		cur+=cnt[gr[arr[cur].second]];
	}
	printf("%I64d",ans);
}