#include<bits/stdc++.h>
using namespace std;
long long w,cnt[11],num[11],ans,fck,r[11];
void solve()
{
	long long cur=0;
	for (int i=1;i<=8;i++)
	{
		cur+=num[i]*i;r[i]=min(6ll,cnt[i]);
		cnt[i]-=r[i];
	}
	if (cur>w)
	{
		for (int i=1;i<=8;i++) cnt[i]+=r[i];
		return;
	}
	for (int i=8;i>=1;i--)
	{
		fck=min(cnt[i],(w-cur)/i);
		cur+=fck*i;
	}
	ans=max(ans,cur);
	for (int i=1;i<=8;i++) cnt[i]+=r[i];
}
void dfs(int i)
{
	if (i==9)
	{
		solve();
		return;
	}
	for (int j=0;j<7 && j<=cnt[i];j++)
	{
		num[i]=j;
		dfs(i+1);
	}
}
int main()
{
	cin>>w;
	for (int i=1;i<=8;i++) cin>>cnt[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}