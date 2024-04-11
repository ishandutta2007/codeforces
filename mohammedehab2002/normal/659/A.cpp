#include <iostream>
using namespace std;
int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	int ans=(n+a+b%n)%n;
	if (!ans)
	ans=n;
	cout << ans;
}