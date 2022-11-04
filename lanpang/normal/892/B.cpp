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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , i , a[maxn] , g , s , l;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	l = n;
	for (i = n ; i >= 1 ; i--)
	{
		if (i <= l) s++;
		g = max(0,i-a[i]-1);
		l = min(l,g);
	}
	cout << s << "\n";
	//system("PAUSE");
	return 0;
}