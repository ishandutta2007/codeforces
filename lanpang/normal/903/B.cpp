#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 5e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int a , b , c , d , e , k , i , g;

int main ()
{
	cin >> a >> b >> e >> c >> d;
	while (c > 0)
	{
		k++;
		c -= b;
		if (c <= 0) break;
		a -= d;
	}
	if (a > 0) cout << k << "\n";
	else
	{
		while (a <= 0)
		{
			g++;
			a += e-d;
		}
		cout << k+g << "\n";
		for (i = 1 ; i <= g ; i++) puts("HEAL");
	}
	for (i = 1 ; i <= k ; i++) puts("STRIKE");
	//system("PAUSE");
	return 0;
}