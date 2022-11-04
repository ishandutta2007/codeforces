#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int x11 , x2 , y11 , y2 , dx , dy , a , b;

int main ()
{
	cin >> x11 >> y11 >> x2 >> y2 >> a >> b;
	dx = fabs(x11-x2);
	dy = fabs(y11-y2);
	if ((dx==0&&dy==0)||(dx==0&&dy%b==0&&(dy/b%2==0))||(dx%a==0&&dy==0&&(dx/a%2==0))||(dx%a==0&&dy%b==0&&((dx/a)%2)==((dy/b)%2)))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	//system("PAUSE");
	return 0;
}