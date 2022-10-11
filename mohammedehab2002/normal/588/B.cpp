#include <iostream>
#include <set>
using namespace std;
set <long long> v;
void getprimediv(long long* n)
{
	long long i;
	for (i=2;i*i<=*n;i++)
	{
		if (*n%i==0)
		{
			v.insert(i);
			while (*n%i==0)
			*n/=i;
		}
	}
	if (*n!=1)
	v.insert(*n);
}
int main()
{
	set <long long> :: iterator it;
	long long n,ans=1;
	cin >> n;
	getprimediv(&n);
	for (it=v.begin();it!=v.end();it++)
	ans*=*it;
	cout << ans;
}