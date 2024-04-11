#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010];pair<int,int> b[100010];int ans[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,cnt=0;cin>>n;set<int> s;
		for (i=1;i<=n;i++) {ans[i]=1;s.insert(i);cin>>a[i];}
		for (i=n;i;i--) if (a[i]<a[i-1]) b[++cnt]={a[i-1]-a[i],i};
		sort(b+1,b+cnt+1);
		for (i=cnt;i;i--)
		{
			while (b[i].first>0)
			{
				auto p=s.lower_bound(b[i].first);
				if (p==s.end()) p--;
				b[i].first-=*p;ans[*p]=b[i].second;s.erase(*p);
			}
		}
		for (i=1;i<=n;i++) cout<<ans[i]<<' ';cout<<endl;
	}
}