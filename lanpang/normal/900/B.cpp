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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

long long c , h , t , i;
double a , b , f;

int main ()
{
	cin >> a >> b >> c;
	while (1)
	{
		i++;
		a *= 10;
		f = a/b;
		h = f;
		if (h % 10 == c)
		{
			cout << i << "\n";
			t = 1;
			break;
		}
		a -= b*h;
		if (i > 10000) break;
	}
	if (!t) cout << "-1\n"; 
	//system("PAUSE");
	return 0;
}