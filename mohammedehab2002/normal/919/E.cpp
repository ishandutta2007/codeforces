#include <iostream>
using namespace std;
long long p;
long long pow_log(int x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%p;
	if (y%2)
	ret=(ret*x)%p;
	return ret;
}
int main()
{
	int a,b;
	long long x,ans=0;
	cin >> a >> b >> p >> x;
	a=pow_log(a,p-2);
	for (int m1=0;m1<p-1;m1++)
	{
		int m2=(b*pow_log(a,m1))%p;
		long long tmp=(m1*p+m2*(p-1)*pow_log(p-1,p-2))%(p*(p-1));
		ans+=(tmp<=x)+(x-tmp)/(p*(p-1));
	}
	cout << ans;
}