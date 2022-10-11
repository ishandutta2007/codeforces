#include <iostream>
#include <algorithm>
using namespace std;
int n,m,arr[200005],s[200005];
long long t;
int go(int d)
{
	int cnt=0;
	long long cur=0,bl=0;
	for (int i=0;i<n;i++)
	{
		if (arr[i]<=d)
		{
			cur+=arr[i];
			bl+=arr[i];
			if (cur>t)
			break;
			cnt++;
			if (cnt%m==0)
			{
				cur+=bl;
				bl=0;
				if (cur>t)
				break;
			}
		}
	}
	return cnt;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d%d%I64d",&n,&m,&t);
		for (int i=0;i<n;i++)
		scanf("%d",&arr[i]),s[i]=arr[i];
		sort(s,s+n);
		int st=0,en=n;
		while (st!=en)
		{
			int mid=(st+en+1)/2;
			if (go(s[mid-1])>=mid)
			st=mid;
			else
			en=mid-1;
		}
		if (st)
		printf("%d %d\n",st,s[st-1]);
		else
		printf("0 1\n");
	}
}