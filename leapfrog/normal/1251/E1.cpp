#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;vector<int>v[200005];
signed main()
{
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld",&n);multiset<int>s;int lst=n,cnt=0,res=0;
		for(int i=0;i<=n;i++) v[i].clear();
		for(int i=1,m,p;i<=n;i++) scanf("%lld%lld",&m,&p),v[m].push_back(p);
		for(int i=n,t;i>=0;i--)
		{
			lst-=v[i].size(),t=i-lst-cnt;
			for(int j=0;j<(int)v[i].size();j++) s.insert(v[i][j]);
			for(;t>=1;t--) cnt++,res+=*s.begin(),s.erase(s.begin());
		}
		printf("%lld\n",res);
	}
	return 0;
}