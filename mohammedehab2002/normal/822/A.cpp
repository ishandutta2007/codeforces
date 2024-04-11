#include <iostream>
using namespace std;
int main()
{
	long long a,b,ans=1;
	cin >> a >> b;
	a=min(a,b);
	for (int i=2;i<=a;i++)
	ans*=i;
	cout << ans;
}