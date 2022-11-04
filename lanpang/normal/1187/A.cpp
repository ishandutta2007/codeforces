#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , s , t;

int main()
{
	int i , j;
	cin >> T;
	while (T--)
	{
		cin >> n >> s >> t;
		cout << max(n-s+1,n-t+1) << "\n";
	}
	return 0;
}