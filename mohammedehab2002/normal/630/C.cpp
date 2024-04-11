#include <iostream>
using namespace std;
int main()
{
	long long n,ans=0;
	cin >> n;
	for (int i=1;i<=n;i++)
	ans+=(1LL<<i);
	cout << ans;
}