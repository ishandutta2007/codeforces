#include <iostream>
#include <fstream>

#include <algorithm>

using namespace std;

struct pii
{
	int first;
	int second;
	int res;
};


pii arr[400000];


int n;

bool cmp(pii a,pii b)
{
	if (a.second<b.second)
		return true;
	else
		return false;
}


bool cmp2(pii a,pii b)
{
	if (a.first<b.first)
		return true;
	else
		return false;
}


int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i].first);
		arr[i].second=i;
	}
	int was=0;
	sort(arr,arr+n,cmp2);
	for (int i=0;i<n;i++)
	{
		int x=max(was+1,arr[i].first);
		arr[i].res=x;
		was=x;
	}
	sort(arr,arr+n,cmp);
	for (int i=0;i<n;i++)
	{
		printf("%d ",arr[i].res);
	}
}