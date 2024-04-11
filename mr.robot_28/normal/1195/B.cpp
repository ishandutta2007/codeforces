#include <bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n, k;
	cin >> n >> k;
	int D = 9 + 8 * n + 8 * k;
	int sqd = sqrt(D);
	int x1 = (-3 + sqd) / 2;
	cout << n - x1;
	return 0;
}