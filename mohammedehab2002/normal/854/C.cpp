#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int,int> > q;
int ans[300005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		q.push(make_pair(a,i));
	}
	long long res=0;
	for (int i=k;i<n+k;i++)
	{
		if (i<n)
		{
			int a;
			scanf("%d",&a);
			q.push(make_pair(a,i));
		}
		pair<int,int> cur=q.top();
		q.pop();
		res+=(i-cur.second)*(long long)cur.first;
		ans[cur.second]=i;
	}
	printf("%I64d\n",res);
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]+1);
}