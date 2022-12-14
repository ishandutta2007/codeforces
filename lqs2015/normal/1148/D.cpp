#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[333333],b[333333];
vector<int> aa,bb;
bool cmp1(int i,int j)
{
	return a[i]<a[j];
}
bool cmp2(int i,int j)
{
	return a[i]>a[j];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]<b[i]) aa.push_back(i);
		else bb.push_back(i);  
	}
	if (aa.size()>bb.size())
	{
		sort(aa.begin(),aa.end(),cmp2);
		printf("%d\n",(int)aa.size());
		for (int i=0;i<aa.size();i++) printf("%d ",aa[i]);
		printf("\n");
	}
	else
	{
		sort(bb.begin(),bb.end(),cmp1);
		printf("%d\n",(int)bb.size());
		for (int i=0;i<bb.size();i++) printf("%d ",bb[i]);
		printf("\n");
	}
	return Accepted;
}