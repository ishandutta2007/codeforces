#include <iostream>
using namespace std;
long long comb(int n,int r)
{
	long long ans=1;
	for (int i=n-r+1;i<=n;i++)
	ans*=i;
	for (int i=r;i>1;i--)
	ans/=i;
	return ans;
}
int main()
{
	int n;
	cin >> n;
	long long ans=comb(n,5);
	cout << (long long)(ans+ans*(n-5)/6+ans*(n-6)*(n-5)/42);
}