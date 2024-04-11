#include <bits/stdc++.h>
using namespace std;
int n, t;
int main()
{
	cin >> n >> t;
	int sco = 5, ans = 0;
	int T = 240 - t;
	for(int i = 1; i <= n; i ++)
		if(T - sco >= 0) T -= sco, sco += 5, ans ++;
	cout << ans;
	return 0;
}