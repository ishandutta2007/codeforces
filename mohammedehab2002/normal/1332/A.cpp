#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a,b,c,d,x,y,x1,y1,x2,y2;
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		int fx=x+b-a,fy=y+d-c;
		if ((x1==x2  && a+b) || (y1==y2 && c+d) || fx<x1 || fx>x2 || fy<y1 || fy>y2)
		cout << "No\n";
		else
		cout << "Yes\n";
	}
}