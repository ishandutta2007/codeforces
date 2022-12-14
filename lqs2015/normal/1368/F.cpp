#include<bits/stdc++.h>
using namespace std;
int n,mx,mxi,ans[1111],cnt,cur,x;
bool fuck[1111];
vector<int> v;
int ask(vector<int> &v)
{
	printf("%d ",(int)v.size());
	for (int i=0;i<v.size();i++) printf("%d ",v[i]);
	printf("\n");fflush(stdout);
	scanf("%d",&x);
	return x;
}
bool check()
{
	int res=0;
	for (int i=1;i<=cnt;i++)
	{
		if (fuck[ans[i]]) res++;
	}
	return (res>=mx);
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		if (n-(n+i-1)/i-(i-1)>mx)
		{
			mx=n-(n+i-1)/i-(i-1);
			mxi=i;
		}
	}
	if (!mx)
	{
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	cur=1;
	while(1)
	{
		if (cur+mxi<=n)
		{
			for (int i=cur;i<cur+mxi-1;i++) ans[++cnt]=i;
			cur+=mxi;
		}
		else
		{
			for (int i=cur;i<n;i++) ans[++cnt]=i;
			break;
		}
	}
	while(!check())
	{
		v.clear();
		for (int i=1;i<=cnt && (int)v.size()<mxi;i++)
		{
			if (fuck[ans[i]]) continue;
			v.push_back(ans[i]);fuck[ans[i]]=1;
		}
		x=ask(v);
		for (int i=0;i<mxi;i++)
		{
			fuck[(x+i-1)%n+1]=0;
		}
	}
	printf("0\n");
	fflush(stdout);
	return 0;
}