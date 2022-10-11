#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long s=0,ans,m=0;
	for (int i=0;i<n;i++)
	{
		long long a;
		cin >> a;
		s+=a;
		m=max(m,a);
	}
	ans=s/(n-1)+(s%(n-1)>0);
	cout << max(ans,m);
}