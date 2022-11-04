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

char a[110] , l;
int n , b[110] , i;

int check(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return 1;
	else return 0;
}

int main()
{
	cin >> n;
	for (i = 0 ; i <= n ; i++)
	{
		a[i] = getchar();
	}
	l = a[1];
	for (i = 2 ; i <= n ; i++)
	{
		if (check(l)&&check(a[i])) b[i] = 1;
		else l = a[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i] == 0) cout << a[i];
	}
	cout << "\n";
	return 0;
}