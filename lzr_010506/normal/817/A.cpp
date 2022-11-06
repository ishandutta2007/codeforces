#include <bits/stdc++.h>
using namespace std;
int X1, Y1, X2, Y2;
int x, y;
int main()
{
	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> x >> y;
	int xx = abs(X2 - X1);
	int yy = abs(Y2 - Y1);
	int cx = xx / x;
	int cy = yy / y;
	if(xx % x || yy % y)
	{
		cout << "NO";
		return 0;
	}
	if(cx % 2 != cy % 2)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";


	return 0;
}