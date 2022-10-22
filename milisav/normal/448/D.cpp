#include <iostream>
#include <cstdio>
using namespace std;
long long int n,m,k;
int bin(long long s)
{
	long long int eq=0;
	long long int sm=0;
	long long int r;
	for(long long int i=1;i<=n;i++)
	{
		r=s/i;
		if(r<=m && r*i==s)
		{
			eq++;
			sm+=(r-1);
		}
		else
		{
			if(r<=m) sm+=r;
			else sm+=m;
		}
	}
	//cout<<s<<" "<<sm<<" "<<eq<<endl;
	if(k>sm && k<=sm+eq) return 0;
	if(k<=sm) return -1;
	else return 1;
}
int main()
{
	cin>>n>>m>>k;
	long long int s,l=1,r;
	r=n*m;
	s=(l+r)/2;
	int q;
	while(l<=r)
	{
		q=bin(s);
		if(q==0)
		{
			cout<<s<<endl;
			return 0;
		}
		else
		{
			if(q==1) l=s+1;
			else r=s-1;
		}
		s=(l+r)/2;
	}
	//cout<<s<<endl;
	return 0;
}