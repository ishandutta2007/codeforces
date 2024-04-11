#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n, m, x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	ll X = abs(x1 - x2), Y = abs(y1 - y2);
	cout << (X + Y <= 4 || X + Y == 5 && X * Y || X + Y == 6 && min(X, Y) >= 2? "First" : "Second");
	return 0;
}