#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << n / 2 << endl;
	while(n > 3)
	{
		n -= 2;
		cout << 2 << " ";
	}
	cout << n;
	return 0;
}