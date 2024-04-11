#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int T,a,m;
vector<int> p;
void init()
{
	int t=m;
	for(int i=2;i*i<=t;i++)
	{
		if(t%i==0)
		{
			p.push_back(i);
			while(t%i==0) t/=i;		
		}
	}
	if(t!=1) p.push_back(t);
	return;	
}
int solve(int x)
{
	if(x<=0) return 0;
	int n=p.size();
	int sum=0;
	for(int ma=1;ma<(1<<n);ma++)
	{
		int cnt=0;
		for(int i=ma;i>0;i-=lowbit(i)) cnt++;
		int k=1;
		for(int i=0;i<n;i++) if(ma&(1<<i)) k*=p[i];
		if(cnt%2) sum+=x/k;
		else sum-=x/k;
	}
	return sum;
}
signed main()
{
	scanf("%lld",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%lld%lld",&a,&m);
		p.clear();
		int g=__gcd(a,m),ans=(m-1)/g+1;
		a/=g;
		int ma=(m-1)/g;
		m/=g;
		init();
		ans-=solve(a+ma)-solve(a-1);
		printf("%lld\n",ans);
	}
	return 0;
}