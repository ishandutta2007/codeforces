#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, n) for(int i = 0; i < n; i ++)
using namespace std;


int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		int sum = 0;
		rep(i, 1, n)
		{
			int x;
			cin >> x;
			sum += x;
		}
		if(sum % n == 0) puts("0");
		else puts("1");
	}

	return 0;
}