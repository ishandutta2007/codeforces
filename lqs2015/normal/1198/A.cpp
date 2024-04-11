#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,l,k,a[444444],b[444444],cnt,num[444444],ans,r,cur,x,sz,L;
map<int,int> mp;
bool check(int l,int r)
{
	x=0;sz=1;
	while(sz<r-l+1) 
	{
		sz*=2;
		x++;
	}
	return (x*n<=L);
}
int main()
{
	scanf("%d%d",&n,&L);L*=8;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	cnt=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=cnt;i++) mp[b[i]]=i;
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
	for (int i=1;i<=n;i++) num[a[i]]++;
	r=1;
	for (int i=1;i<=cnt;i++)
	{
		while(r<=cnt)
		{
			if (check(i,r)) 
			{
				cur+=num[r];
				r++;
			}
			else break;
		}
		ans=max(ans,cur);
		cur-=num[i];
	}
	printf("%d\n",n-ans);
	return Accepted;
}