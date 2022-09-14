#include<iostream>
#include<map>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long a[555],ans=1,mod=998244353;int n;
long long is4(long long a)
{
	long long l=1,r=40000;
	while(r-l>1)
	{
		long long m=(l+r)/2;
		if(m*m*m*m>a)r=m;
		else l=m;
	}
	return l;
}
long long is3(long long a)
{
	long long l=1,r=2000000;
	while(r-l>1)
	{
		long long m=(l+r)/2;
		if(m*m*m>a)r=m;
		else l=m;
	}
	return l;
}
long long is2(long long a)
{
	long long l=1,r=2000000000;
	while(r-l>1)
	{
		long long m=(l+r)/2;
		if(m*m>a)r=m;
		else l=m;
	}
	return l;
}
main()
{
	cin>>n;
	map<long long,int>M,A;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		long long l=is4(a[i]);
		if(l*l*l*l==a[i])M[l]+=4;
		else
		{
			l=is3(a[i]);
			if(l*l*l==a[i])M[l]+=3;
			else
			{
				l=is2(a[i]);
				if(l*l==a[i])M[l]+=2;
				else A[a[i]]++;
			}
		}
	}
	for(map<long long,int>::iterator it=A.begin();it!=A.end();it++)
	{
		for(map<long long,int>::iterator jt=A.begin();jt!=A.end();jt++)
		{
			long long k=gcd(it->first,jt->first);
			if(k>1&&k!=it->first)
			{
				M[k]+=it->second;
				M[it->first/k]+=it->second;
				it->second=0;
				break;
			}
		}
	}
	for(map<long long,int>::iterator it=A.begin();it!=A.end();it++)
	{
		if(it->second==0)continue;
		for(map<long long,int>::iterator jt=M.begin();jt!=M.end();jt++)
		{
			if(it->first%jt->first==0)
			{
				jt->second+=it->second;
				M[it->first/jt->first]+=it->second;
				it->second=0;
				break;
			}
		}
	}
	for(map<long long,int>::iterator it=A.begin();it!=A.end();it++)
	{
		ans=ans*(it->second+1)*(it->second+1)%mod;
	}
	for(map<long long,int>::iterator it=M.begin();it!=M.end();it++)ans=ans*(it->second+1)%mod;
	cout<<ans<<endl;
}