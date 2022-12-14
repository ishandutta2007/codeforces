#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int a[111111],b[111111],n,pos[111111],cha[111111],ans[111111],mn;
set<int>::iterator aa,bb;
set<int> s;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) pos[a[i]]=i;
	for (int i=1;i<=n;i++) cha[b[i]]=i-pos[b[i]];
	mn=1e9;
	for (int i=1;i<=n;i++)
	{
		mn=min(mn,abs(cha[i]));
	}
	for (int i=1;i<=n;i++) ans[i]=1e9;
	ans[1]=mn;
	for (int i=1;i<n;i++)
	{
		s.insert(cha[b[i]]);
		if (s.find(i-n)!=s.end())
		{
			ans[i+1]=0;
			continue;
		}
		aa=s.lower_bound(i-n);bb=s.upper_bound(i-n);
		if (aa==s.begin()) aa=s.end();
		else aa--;
		if (aa!=s.end()) ans[i+1]=abs(*aa+n-i);
		if (bb!=s.end()) ans[i+1]=min(ans[i+1],abs(*bb+n-i));
	}
	s.clear();
	for (int i=n;i>=2;i--)
	{
		s.insert(cha[b[i]]);
		if (s.find(i-1)!=s.end())
		{
			ans[i]=0;
			continue;
		}
		aa=s.lower_bound(i-1);bb=s.upper_bound(i-1);
		if (aa==s.begin()) aa=s.end();
		else aa--;
		if (aa!=s.end()) ans[i]=min(ans[i],abs(*aa-i+1));
		if (bb!=s.end()) ans[i]=min(ans[i],abs(*bb-i+1)); 
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}