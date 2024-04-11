#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
	long long n,k,a,b;
	cin>>n>>k>>a>>b;
	long long tot=0;
	if(k==1)
	{
		cout<<(n-1)*a; return 0;
	}
	while(n)
	{
		if(n<k)
		{
			tot+=a*(n-1);
			break;
		}
		tot+=min(b,a*(n/k*k-n/k))+a*(n-n/k*k);
		n/=k;
	}
	cout<<tot;
	return 0;
}