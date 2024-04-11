#include <iostream>
using namespace std;
int main()
{
	int n,m,i;
	cin >> n >> m;
	if (m==10)
	{
		if (n==1)
		{
			cout << -1;
			return 0;
		}
		n--;
	}
	cout << m;
	for (i=0;i<n-1;i++)
	cout << 0;
}