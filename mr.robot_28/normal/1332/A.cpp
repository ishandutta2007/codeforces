#include <bits/stdc++.h>
using namespace std;
#define double long double
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, d;
		cin >> a >> b >>  c>> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int deltax = b - a;
		int deltay = d - c;
		if(x + deltax >= x1 && x + deltax <= x2 && y + deltay >= y1 && y + deltay <= y2)
		{
			if((a != 0 || b != 0) && x == x1 && x == x2)
			{
				cout << "No\n";
				continue;
			}
			if((c != 0 || d != 0) && y == y1 && y == y2)
			{
				cout << "No\n";
				continue;
			}
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
    return 0;
}