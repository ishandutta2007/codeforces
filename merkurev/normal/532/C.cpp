#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

string p = "Polycarp";
string v = "Vasiliy";

void _p()
{
	printf("%s\n", p.c_str() );
	exit(0);
}
void _v()
{
	printf("%s\n", v.c_str() );
	exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int xp, yp;
	int xv, yv;
	scanf("%d%d%d%d", &xp, &yp, &xv, &yv);

	while (xp + yp != 0 && xv + yv != 0)
	{
		int dv = yv - xv;
		int dp = yp - xp;
		
		int dx = 0, dy = 0;
		if (dp < dv)
			dx = 1;
		else
			dy = 1;
	
		if (xp - dx < 0 || yp - dy < 0)
			swap(dx, dy);
		xp -= dx;
		yp -= dy;
		if (xp == xv && yp == yv)
			_v();
		
		if (xv > 0)
			xv --;
		if (yv > 0)
			yv --;
	
		if (xp == xv && yp == yv)
			_p();
	}
	if (xp + yp == 0)
		_p();
	else
		_v();



	return 0;
}