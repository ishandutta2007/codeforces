#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010],l[200010],r[200010];
int main()
{
	int n,i,j,ans=0;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++)
	{
		if (!l[a[i]]) l[a[i]]=r[a[i]]=i;
		else r[a[i]]=i;
	}
	for (i=1;i<=n;i++) if (i==l[a[i]] && l[a[i]]!=r[a[i]])
	{
		int u=r[a[i]],res=r[a[i]]-i-1;j=i+1;
		while (1)
		{
			int o=0;
			for (;j<u;j++)
			{
				o=max(o,r[a[j]]);
			}
			if (o<=u) break;
			else res+=o-u-1,u=o;
		}
		ans+=res;i=u;
	}
	cout<<ans;
}