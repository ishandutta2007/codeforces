#include <iostream>
using namespace std;
int main()
{
	long long l,r;
	cin >> l >> r;
	for (int i=62;i>=0;i--)
	{
		if ((l&(1LL<<i))!=(r&(1LL<<i)))
		{
			cout << (1LL<<(i+1))-1;
			return 0;
		}
	}
	cout << 0;
}