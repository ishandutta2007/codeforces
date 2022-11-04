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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a , a1 , a2 , a3 , a4;

int main ()
{
	int i;
	for (i = 1 ; i <= 3 ; i++)
	{
		cin >> a;
		if (a == 1) a1++;
		if (a == 2) a2++;
		if (a == 3) a3++;
		if (a == 4) a4++;
	}
	if (a1 >= 1 || a2 >= 2 || (a2 == 1 && a4 == 2) || a3 == 3) cout << "YES\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}