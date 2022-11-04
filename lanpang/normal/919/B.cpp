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
const int maxn = 1e4+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int k , v;

int check(int f)
{
	int ret=0;
	while (f > 0)
	{
		ret += f%10;
		f /= 10;
	}
	return ret;
}

int main ()
{
	cin >> k;
	int i , j;
	i = 0;
	j = 0;
	while (j < k)
	{
		i++;
		if (check(i) == 10) j++;
	}
	cout << i << "\n";
	//system("PAUSE");
	return 0;
}