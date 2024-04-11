#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
const int inf = 1e9;
int main()
{
	int n, a, b , c;
	cin >> n >> a >> b >> c;
	if(a <= b && a <= c)
	{
		cout << (n - 1) * a;
	}
	else if(b <= a && b <= c)
	{
		cout << (n - 1) * b;
	}
	else
	{
		if(n == 1)
		{
			cout << 0;
			return 0;
		}
		cout << min(a, b) + (n - 2) * c;
	}
	return 0;
}