#include <bits/stdc++.h>
#define int long long

using namespace std;

int base=309989, base1=309989, mod=998244353, mod1=1000000207, mod3=1000000007, mod2=1000000009, base2=3218181, base3=21114121;
stack<int> s;
int a[300005], m[300005], m1[300005], m2[300005], m3[300005];
int ans=0;

void solve(int l, int r)
{
	if(l>r) return;
	map<pair<int, int> , int> cnt;
	cnt.clear();
	int mid=(l+r)/2;
	while(s.size()) s.pop();
	int cur=0, cur1=0, cur2=0, cur3=0;
	for(int i=mid; i>=l; i--)
	{
		if(s.size()&&s.top()==a[i])
		{
			cur=(cur+mod-(a[i]*m[s.size()])%mod)%mod;
			cur1=(cur1+mod1-(a[i]*m1[s.size()])%mod1)%mod1;
			cur2=(cur2+mod2-(a[i]*m2[s.size()])%mod2)%mod2;
			cur3=(cur3+mod3-(a[i]*m3[s.size()])%mod3)%mod3;
			s.pop();
			cnt[{cur*1000000010+cur1, cur2*1000000010+cur3}]++;
		}
		else
		{
			s.push(a[i]);
			cur=(cur+mod+(a[i]*m[s.size()])%mod)%mod;
			cur1=(cur1+mod1+(a[i]*m1[s.size()])%mod1)%mod1;
			cur2=(cur2+mod2+(a[i]*m2[s.size()])%mod2)%mod2;
			cur3=(cur3+mod3+(a[i]*m3[s.size()])%mod3)%mod3;
			cnt[{cur*1000000010+cur1, cur2*1000000010+cur3}]++;
		}
		// cout<<cur<<endl;
	}
	while(s.size()) s.pop();
	cur=0;
	cur1=0;
	cur2=0;
	cur3=0;
	for(int i=mid+1; i<=r; i++)
	{
		if(s.size()&&s.top()==a[i])
		{
			cur=(cur+mod-(a[i]*m[s.size()])%mod)%mod;
			cur1=(cur1+mod1-(a[i]*m1[s.size()])%mod1)%mod1;
			cur2=(cur2+mod2-(a[i]*m2[s.size()])%mod2)%mod2;
			cur3=(cur3+mod3-(a[i]*m3[s.size()])%mod3)%mod3;
			s.pop();
			ans+=cnt[{cur*1000000010+cur1, cur2*1000000010+cur3}];
		}
		else
		{
			s.push(a[i]);
			cur=(cur+mod+(a[i]*m[s.size()])%mod)%mod;
			cur1=(cur1+mod1+(a[i]*m1[s.size()])%mod1)%mod1;
			cur2=(cur2+mod2+(a[i]*m2[s.size()])%mod2)%mod2;
			cur3=(cur3+mod3+(a[i]*m3[s.size()])%mod3)%mod3;
			ans+=cnt[{cur*1000000010+cur1, cur2*1000000010+cur3}];
		}
		// cout<<cur<<endl;
	}
	ans+=cnt[{0, 0}];
	solve(l, mid-1);
	solve(mid+1, r);
}

signed main()
{
	ios::sync_with_stdio(false);
	m[0]=1, m1[0]=1;
	for(int i=1; i<=300000; i++)
	{
		m[i]=m[i-1]*base;
		m[i]%=mod;
		m1[i]=m1[i-1]*base1;
		m1[i]%=mod1;
		m2[i]=m2[i-1]*base2;
		m2[i]%=mod2;
		m3[i]=m3[i-1]*base3;
		m3[i]%=mod3;
	}
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		ans=0;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		solve(1, n);
		cout<<ans<<endl;
	}
}