#include<iostream>
#include<map>
using namespace std;
long long n,a,q;
map<long long,long long> s,t,m;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		s[a]++;
		t.clear();
		for (map<long long,long long>::iterator it=s.begin();it!=s.end();it++)
		{
			t[gcd(it->first,a)]+=it->second;
			m[gcd(it->first,a)]+=it->second;
		}
		s=t;
	}
	cin>>q;
	while(q--)
	{
		cin>>a;
		cout<<m[a]<<endl;
	}
	return 0;
}