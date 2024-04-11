#include<bits/stdc++.h>
using namespace std;
int n,p[111111],mx[111111],cur,pre[111111],suf[111111],lef[111111],rig[111111],ans,l[111111],r[111111],cc;
bool check(int i)
{
	if (max(pre[i-lef[i]-1],suf[i+rig[i]+1])>=max(lef[i],rig[i])) return 0;
	if (lef[i])
	{
		if (l[i-lef[i]]>=max(lef[i],rig[i])) return 0;
		cc=(lef[i]-1)/2*2+1;
		if (cc>=rig[i]) return 0;
	}
	if (rig[i])
	{
		if (r[i+rig[i]]>=max(lef[i],rig[i])) return 0;
		cc=(rig[i]-1)/2*2+1;
		if (cc>=lef[i]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
	{
		if (i>1 && p[i-1]>p[i]) cur++;
		else cur=0;
		mx[i]=cur;l[i]=cur;
	}
	for (int i=n;i>=1;i--)
	{
		if (i<n && p[i+1]>p[i]) cur++;
		else cur=0;
		mx[i]=max(mx[i],cur);r[i]=cur;
	}
	for (int i=1;i<=n;i++) pre[i]=max(pre[i-1],mx[i]);
	for (int i=n;i>=1;i--) suf[i]=max(suf[i+1],mx[i]);
	for (int i=1;i<=n;i++)
	{
		if (i>1 && p[i-1]<p[i]) cur++;
		else cur=0;
		lef[i]=cur;
	}
	for (int i=n;i>=1;i--)
	{
		if (i<n && p[i+1]<p[i]) cur++;
		else cur=0;
		rig[i]=cur;
	}
	for (int i=1;i<=n;i++)
	{
		ans+=check(i);
	}
	printf("%d\n",ans);
	return 0;
}