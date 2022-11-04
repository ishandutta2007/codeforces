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

int a , b , t , ans;

int check1(int x , int y)
{
	if (x/10 == 7 || x%10 == 7 || y/10 == 7 || y%10 == 7) return 0;
	else return 1;
}

int main ()
{
	cin >> t >> a >> b;
	while (check1(a,b))
	{
		b -= t;
		if (b < 0) 
		{
			b += 60;
			a--;
			if (a < 0) a += 24;
		}
		ans++;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}