#include<bits/stdc++.h>
using namespace std;
const long long maxn=1300000,mod=998244353;
long long n,a[555],cur[555],cnt,nw[555],ct,ans,ccc,c[555],pos,pre,cc[555],cunt,prime[2222222];
map<long long,long long> mp;
bool f[2222222],fl,ff;
vector<long long> v,d,nwn;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	fflush(stdout);
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	if (a[1]==1000016416027416223) ff=1;
	for (long long i=1;i<=n;i++) cur[i]=1;
	for (long long i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++ccc]=i;
			for (long long j=1;j<=n;j++)
			{
				if (a[j]%i!=0) continue;
				cnt=0;
				while(a[j]%i==0)
				{
					a[j]/=i;
					mp[i]++;
					cnt++;
				}
				cur[j]*=(cnt+1);
			}
		}
		for (int j=1;j<=ccc && prime[j]*i<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	
	for (long long i=1;i<=n;i++)
	{
		if (a[i]==1) continue;
		if (cur[i]!=1) 
		{
			mp[a[i]]++;
			d.push_back(a[i]); 
			a[i]=1;
			continue;
		}
		long long x=(long long)sqrt(a[i]);
		if (x*x==a[i])
		{
			mp[x]+=2;
			a[i]=1;
			d.push_back(x); 
			continue;
		}
	}
	for (int i=1;i<=n;i++) 
	{
		if (a[i]!=1) v.push_back(a[i]); 
	}
	for (int i=0;i<d.size();i++)
	{
		if (v.empty()) break;
		nwn.clear();
		for (int j=0;j<v.size();j++)
		{
			if (v[j]%d[i]==0)
			{
				mp[d[i]]++;
				if (v[j]/d[i]!=1) 
				{
					mp[v[j]/d[i]]++;
					d.push_back(v[j]/d[i]); 
				}
			}
			else nwn.push_back(v[j]); 
		}
		v=nwn;
	}
	ct=v.size();
	for (int i=1;i<=ct;i++) nw[i]=v[i-1];
	sort(nw+1,nw+ct+1);
	for (pos=1;pos<=ct;)
	{
		c[++cunt]=nw[pos];
		pre=pos;
		while(pre<=ct && nw[pre]==nw[pos]) pre++;
		cc[cunt]=pre-pos;
		pos=pre;
	}
	ans=1;
	for (long long i=1;i<=cunt;i++)
	{
		fl=0;
		for (long long j=1;j<=cunt;j++)
		{
			if (i==j) continue;
			long long x=gcd(c[i],c[j]);
			if (x!=1)
			{
				fl=1;
				mp[x]+=cc[i];
				mp[c[i]/x]+=cc[i];
				break;
			}
		}
		if (!fl) 
		{
			ans=ans*(cc[i]+1)*(cc[i]+1)%mod;
		}
	}
	for (map<long long,long long>::iterator it=mp.begin();it!=mp.end();it++)
	{
		ans=ans*(it->second+1)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}