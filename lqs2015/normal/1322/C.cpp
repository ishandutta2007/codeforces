#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=500000;
int n,test,m,pw1[555555],pw2[555555],x,y;
int hsh1[555555],hsh2[555555];
long long c[555555],ans;
int p1,p2,p3;
bool isprime(int n)
{
	int x=sqrt(n);
	for (int i=2;i<=x;i++)
	{
		if (n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
mt19937 rnd(time(0));
map<pair<int,int>,long long> mp;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	p1=1000000000+(rnd()%100000);
	while(!isprime(p1)) p1++;
	p2=1000000000+(rnd()%100000);
	while(!isprime(p2)) p2++;
	p3=500000+(rnd()%100000);
	while(!isprime(p2)) p3++;
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=maxn;i++) pw1[i]=1ll*pw1[i-1]*p3%p1;
	for (int i=1;i<=maxn;i++) pw2[i]=1ll*pw2[i-1]*p3%p2;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&c[i]);
			hsh1[i]=hsh2[i]=0;
		}
		mp.clear();
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			hsh1[y]=(hsh1[y]+pw1[x])%p1;
			hsh2[y]=(hsh2[y]+pw2[x])%p2;
		}
		for (int i=1;i<=n;i++) 
		{
			if (!hsh1[i] && !hsh2[i]) continue;
			mp[make_pair(hsh1[i],hsh2[i])]+=c[i];
		}
		ans=0;
		for (map<pair<int,int>,long long>::iterator it=mp.begin();it!=mp.end();it++)
		{
			ans=gcd(ans,it->second);
		}
		printf("%lld\n",ans);
	}
	return Accepted;
}