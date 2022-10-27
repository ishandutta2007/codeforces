
#include<bits/stdc++.h>
 
using namespace std;
signed main(){
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	if(x3 <= x1 && x4 >= x2)
	{
		if(y3 <= y1)
		{
			y1 = max(y1, y4);
		}
		if(y4 >= y2)
		{
			y2 = min(y2, y3);
		}
		if(y1 > y2)
		{
			cout << "NO";
			return 0;
		}
	}
	if(y3 <= y1 && y4 >= y2)
	{
		if(x3 <= x1)
		{
			x1 = max(x1, x4);
		}
		if(x4 >= x2)
		{
			x2 = min(x2, x3);
		}
		if(x1 > x2)
		{
			cout << "NO";
			return 0;
		}
	}
	if(x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}