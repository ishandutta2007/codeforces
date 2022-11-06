#include <bits/stdc++.h>
using namespace std;
int n, t, k, d;
int main()
{
	cin >> n >> t >> k >> d;

	bool ans = 0;
	int now = 0;
	while(n)
	{
		n -= k;
		if(n <= 0) break;
		now += t;
		if(now > d) {cout << "YES"; return 0;}
	}
	cout << "NO";
}