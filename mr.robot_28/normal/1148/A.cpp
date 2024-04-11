#include <bits/stdc++.h> 
using namespace std;
int main()
{
	#define int long long
	int a, b, c;
	cin >> a >> b >> c;
	if(a > b + 1)
	{
		cout << b + b + 1 + 2 * c;
	}
	else if(a == b + 1 || a == b || a == b - 1)
	{
		cout << a + b + 2 * c;
	}
	else
	{
		cout << a + a + 1 + 2 * c;
	}
   	return 0;
}