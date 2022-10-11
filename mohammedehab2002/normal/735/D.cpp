#include <iostream>
using namespace std;
bool prime(int n)
{
	bool ans=1;
	for (int i=2;i*i<=n;i++)
	ans&=(bool)(n%i);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	if (prime(n))
	cout << 1;
	else if (n%2==0)
	cout << 2;
	else
	cout << 2+!prime(n-2);
}