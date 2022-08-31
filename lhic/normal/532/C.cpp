#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

int main()
{
	int xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;
	while (true)
	{
		if ((xv - xp >= yv - yp) && (yp != 0)) yp--;
		else xp--;
		if (xp + yp == 0)
		{
			cout << "Polycarp" << endl;
			return 0;
		}
		xv--, yv--;
		if (xv < 0) xv = 0;
		if (yv < 0) yv = 0;
		if ((xv == xp) && (yv == yp))
		{
			cout << "Polycarp" << endl;
			return 0;
		}
		if ((xv == 0) && (yv == 0))
		{
			cout << "Vasiliy" << endl;
			return 0;
		}
	}
	return 0;
}