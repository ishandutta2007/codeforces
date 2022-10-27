#include <bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int x;
	cin >> x;
	for(int i = 2; i <= x; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(i % j == 0 &&  i * j > x && i / j < x)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << -1;
    return 0;
}