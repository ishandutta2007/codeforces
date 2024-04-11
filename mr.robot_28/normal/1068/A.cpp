#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	long long n, m, k, l;
	cin >> n >> m >> k >> l;
	if((k + l + m - 1) / m * m > n)
	{
		cout << -1;
		return 0;
	}
	long long h = (k + l) / m + ((k + l) % m != 0);
	cout << h;
	return 0;
}