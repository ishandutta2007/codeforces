
#include <bits/stdc++.h>
using namespace std;

signed main() {
	#define int long long
	int n;
	cin >> n;
	int cnt = 0;
	int j = n;
	int imin = -1;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(j % i == 0)
		{
			imin = i;
			cnt++;
		}
		while(j % i == 0)
		{
			j = j / i;
		}
	}
	if(j != 1 && j != n)
	{
		imin = j;
		cnt++;
	}
	if(cnt == 1)
	{
		cout << imin;
	}
	else if(cnt == 0)
	{
		cout << n;
	}
	else
	{
		cout << 1;
	}
	return 0;
}