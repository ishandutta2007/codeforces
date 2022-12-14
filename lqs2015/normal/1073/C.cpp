#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,x,y,r,ans;
pair<int,int> pre[222222],suf[222222],cur;
char c[222222];
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for (int i=0;i<n;i++)
	{
		if (c[i]=='U') 
		{
			if (!i) pre[i]=make_pair(0,1);
			else pre[i]=make_pair(pre[i-1].first,pre[i-1].second+1);
		}
		else if (c[i]=='D')
		{
			if (!i) pre[i]=make_pair(0,-1);
			else pre[i]=make_pair(pre[i-1].first,pre[i-1].second-1);
		}
		else if (c[i]=='L') 
		{
			if (!i) pre[i]=make_pair(-1,0);
			else pre[i]=make_pair(pre[i-1].first-1,pre[i-1].second);
		}
		else
		{
			if (!i) pre[i]=make_pair(1,0);
			else pre[i]=make_pair(pre[i-1].first+1,pre[i-1].second);
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		if (c[i]=='U') 
		{
			suf[i]=make_pair(suf[i+1].first,suf[i+1].second+1);
		}
		else if (c[i]=='D')
		{
			suf[i]=make_pair(suf[i+1].first,suf[i+1].second-1);
		}
		else if (c[i]=='L') 
		{
			suf[i]=make_pair(suf[i+1].first-1,suf[i+1].second);
		}
		else
		{
			suf[i]=make_pair(suf[i+1].first+1,suf[i+1].second);
		}
	}
	scanf("%d%d",&x,&y);
	ans=1e9;r=-1;
	for (int i=0;i<n;i++)
	{
		while(r<n)
		{
			if (!i) cur=suf[r+1];
			else cur=make_pair(pre[i-1].first+suf[r+1].first,pre[i-1].second+suf[r+1].second);
			if ((abs(x-cur.first)+abs(y-cur.second)-(r-i+1))%2!=0)
			{
				printf("-1\n");
				return 0;
			}
			if ((abs(x-cur.first)+abs(y-cur.second)-(r-i+1))>0) r++;
			else break;
		}
		if (r<n) ans=min(ans,r-i+1);
	}
	if (ans==1e9) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}