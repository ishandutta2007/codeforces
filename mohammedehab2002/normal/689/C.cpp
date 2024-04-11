#include <iostream>
using namespace std;
long long check(long long n)
{
	long long sum=0;
	for (long long k=2;k*k*k<=n;k++)
	sum+=n/(1LL*k*k*k);
	return sum;
}
int main()
{
	long long m,n=-1;
	cin >> m;
	long long st=0,en=10000000000000000;
	while (st<en)
	{
		long long mid=(st+en)/2;
		if (check(mid)<m)
		st=mid+1;
		else
		en=mid;
	}
	if (check(st)==m)
	n=st;
	cout << n;
}