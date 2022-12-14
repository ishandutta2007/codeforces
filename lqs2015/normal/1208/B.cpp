#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[2222],arr[2222],cnt,num[2222],r,ct,ans;
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) arr[i]=a[i];
	sort(arr+1,arr+n+1);
	cnt=unique(arr+1,arr+n+1)-arr-1;
	for (int i=1;i<=cnt;i++) mp[arr[i]]=i;
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
	for (int i=1;i<=n;i++) num[a[i]]++;
	r=0;
	for (int i=1;i<=cnt;i++) 
	{
		if (num[i]>1) ct++;
	}
	ans=1e9;
	for (int i=1;i<=n;i++)
	{
		while(r<=n && ct)
		{
			r++;num[a[r]]--;
			if (num[a[r]]==1) ct--;
		}
		if (r<=n)
		{
			if (r<i) ans=0;
			else ans=min(ans,r-i+1);
		}
		num[a[i]]++;
		if (num[a[i]]==2) ct++; 
	}
	printf("%d\n",ans);
	return Accepted;
}