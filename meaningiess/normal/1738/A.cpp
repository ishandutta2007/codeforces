#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,int> a[1000010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,s=0;cin>>n;
		for (i=1;i<=n;i++) {cin>>a[i].second;s+=a[i].second;}
		for (i=1;i<=n;i++) cin>>a[i].first;
		s=min(s,n-s);
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		if (s*2<n)
		{
			ll ans1=0,ans2=0,t[2]={s,s};
			for (i=1;i<=n;i++) if (t[a[i].second])ans1+=2*a[i].first,t[a[i].second]--;else ans1+=a[i].first;
			cout<<ans1<<endl;
		}
		else
		{
			ll ans1=0,ans2=0,t[2]={s-1,s};
			for (i=1;i<=n;i++) if (t[a[i].second])ans1+=2*a[i].first,t[a[i].second]--;else ans1+=a[i].first;
			ans2=0,t[0]=s;t[1]=s-1;
			for (i=1;i<=n;i++) if (t[a[i].second])ans2+=2*a[i].first,t[a[i].second]--;else ans2+=a[i].first;
			cout<<max(ans1,ans2)<<endl;
		}
	}
}