#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = 1000000007;

using namespace std;

bool check(LL x)
{
	x = abs(x);
	while(x)
	{
		if(x % 10 == 8) return true;
		x /= 10;
	}
	return false;
}

bool solve()
{
	LL a;

	cin >> a;

	for(LL i(a + 1);;i++)
	{
		if(check(i))
		{
			cout << i - a << '\n';
			return true;
		}
	}

    return true;
}

int main()
{
	//while(solve());
    solve();

    return 0;
}