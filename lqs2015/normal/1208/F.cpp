#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[1111111],cnt[2222222],ans,msk,cur;
bool vis[2222222];
vector<int> v;
void add(int x)
{
	vis[x]=1;v.push_back(x);
	if (cnt[x]>=2) return;
	cnt[x]++;
	for (int i=0;i<=20;i++)
	{
		if (x&(1<<i))
		{
			if ((cnt[x^(1<<i)]<2) && !vis[x^(1<<i)]) add(x^(1<<i));
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	add(a[n]);
	for (int i=0;i<v.size();i++) vis[v[i]]=0;
	v.clear();
	add(a[n-1]);
	for (int i=n-2;i>=1;i--)
	{
		cur=a[i];msk=0;
		for (int j=20;j>=0;j--)
		{
			if (a[i]&(1<<j)) continue;
			msk^=(1<<j);
			if (cnt[msk]>=2) cur+=(1<<j);
			else msk^=(1<<j);
		}
		ans=max(ans,cur);
		for (int i=0;i<v.size();i++) vis[v[i]]=0;
		v.clear();
		add(a[i]);
	}
	printf("%d\n",ans);
	return Accepted;
}