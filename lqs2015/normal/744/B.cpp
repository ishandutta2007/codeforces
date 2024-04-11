#include<bits\stdc++.h>
using namespace std;
int ans[1111],n,cur,l,r,mid,a[1111];
vector<pair<int,int> > v,s;
int main()
{
	scanf("%d",&n);
	v.push_back(make_pair(1,n));
	for (int i=1;i<=n;i++) ans[i]=1e9;
	for (int i=1;i<=10;i++)
	{
		cur=0;
		for (int j=0;j<v.size();j++)
		{
			l=v[j].first;r=v[j].second;mid=(l+r)/2;
			cur+=(mid-l+1);
		}
		if (cur)
		{
			printf("%d\n",cur);
			fflush(stdout);
			for (int j=0;j<v.size();j++)
			{
				l=v[j].first;r=v[j].second;mid=(l+r)/2;
				for (int k=l;k<=mid;k++) printf("%d ",k);
			}
			printf("\n");
			fflush(stdout);
			for (int j=1;j<=n;j++) scanf("%d",&a[j]);
			for (int j=0;j<v.size();j++)
			{
				l=v[j].first;r=v[j].second;mid=(l+r)/2;
				for (int k=mid+1;k<=r;k++) ans[k]=min(ans[k],a[k]);
			}
		}
		cur=0;
		for (int j=0;j<v.size();j++)
		{
			l=v[j].first;r=v[j].second;mid=(l+r)/2;
			cur+=(r-mid);
		}
		if (cur)
		{
			printf("%d\n",cur);
			fflush(stdout);
			for (int j=0;j<v.size();j++)
			{
				l=v[j].first;r=v[j].second;mid=(l+r)/2;
				for (int k=mid+1;k<=r;k++) printf("%d ",k);
			}
			printf("\n");
			fflush(stdout);
			for (int j=1;j<=n;j++) scanf("%d",&a[j]);
			for (int j=0;j<v.size();j++)
			{
				l=v[j].first;r=v[j].second;mid=(l+r)/2;
				for (int k=l;k<=mid;k++) ans[k]=min(ans[k],a[k]);
			}
		}
		s.clear();
		for (int j=0;j<v.size();j++)
		{
			l=v[j].first;r=v[j].second;mid=(l+r)/2;
			v[j].second=mid;s.push_back(make_pair(mid+1,r)); 
		}
		for (int j=0;j<s.size();j++) v.push_back(s[j]); 
	}
	printf("-1\n");
	fflush(stdout);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}