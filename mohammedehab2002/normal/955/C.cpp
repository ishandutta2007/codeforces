#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
long long lim=1000000000;
long long pow_log(int x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	if (ret>lim)
	return (1LL<<60);
	ret*=ret;
	if (y%2)
	{
		if (lim*lim/ret>=x)
		return ret*x;
		return (1LL<<60);
	}
	return ret;
}
set<long long> s;
vector<long long> v;
int main()
{
	for (int p=3;p<60;p+=2)
	{
		for (int x=2;pow_log(x,p)!=(1LL<<60);x++)
		{
			int tmp=sqrt(x);
			if (tmp*tmp!=x)
			s.insert(pow_log(x,p));
		}
	}
	for (long long i:s)
	v.push_back(i);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		long long l,r;
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l)+(long long)sqrt(r)-(long long)sqrt(l-1));
	}
}