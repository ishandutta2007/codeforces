#include <iostream>
#include <cstdio>
using namespace std;
long long int m,n,k;
inline bool pos(long long int d)
{
	long long int m1=m;
	m1=m1-d;
	if(d<k) 
	{
		m1=m1-d*(d-1)/2;
		m1=m1-(k-d);
	}
	else m1=m1+(k-1)*(k-2*d)/2;
	long long int k1=n-k+1;
	if(d<k1) 
	{
		m1=m1-d*(d-1)/2;
		m1=m1-(k1-d);
	}
	else m1=m1+(k1-1)*(k1-2*d)/2;
	if(m1<0) return false;
	return true;
}
int main()
{
	
	
	scanf("%lld %lld %lld",&n,&m,&k);
	long long int l=1;
	long long int r=1000000004;
	long long int mid=(l+r)/2;
	while(l<r-1)
	{
		if(pos(mid)) l=mid; 
		else r=mid-1;
		mid=(l+r)/2;
	}
	while(!pos(mid)) mid--;
	while(pos(mid+1)) mid++;
	printf("%lld",mid);
	return 0;
}