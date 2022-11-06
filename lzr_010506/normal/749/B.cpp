#include <bits/stdc++.h>
using namespace std;
int xx, yy, x, y, xxx, yyy;
int main()
{
	cin >> x >> y >> xx >> yy >> xxx >> yyy;
	cout << 3 << endl;
	cout << x + xxx - xx << " " << y + yyy - yy << endl;
	cout << xx + x - xxx << " " << yy + y - yyy << endl;
	cout << xxx + xx - x << " " << yyy + yy - y << endl;

	return 0;
}