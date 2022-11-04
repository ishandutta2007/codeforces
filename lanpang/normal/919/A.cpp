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

double f , a , b , c , m;
int n , i;

int main ()
{
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a >> b;
		c = a*m/b;
		if (i == 1) f = c;
		else f = min(f,c);
	}
	printf("%.8lf",f);
	//system("PAUSE");
	return 0;
}