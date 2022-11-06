#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	a -= c;
	b -= c;
	d -= c;
	int mask = 0;
	if(d == 0)
	{
		if(a > 0) a --, mask |= 1;
		else b --, mask |= 2;
	}
	if(d == 1)
	{
		a --;
		b --;
		mask |= 3;
	}
	if(a < 0 || b < 0 || d < -1 || d > 1) cout << -1;
	else
	{
		if(mask & 2) cout << 7;
		for(int i = 1; i <= a; i ++) cout << 4;
		for(int i = 1; i <= c; i ++) cout << 47;
		for(int i = 1; i <= b; i ++) cout << 7;
		if(mask & 1) cout << 4;
	}

	return 0;
}