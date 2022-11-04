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

LL n , a[maxn] , l , r , s , ss , t;

int main ()
{
	int i;
	cin >> n;
	s = ((1+n)*n)/2;
	t = s%2;
	s /= 2;
	l = 0;
	r = 0;
	ss = 0;
	for (i = 1 ; i <= n ; i++)
	{
		ss -= l;
		l++;
		while (r < n && ss <= s)
		{
			r++;
			ss += r;
		}
		if (ss > s)
		{
			ss -= r;
			r--;
		}
		if (ss == s) break;
	}
	cout << t << "\n" << r-l+1;
	for (i = l ; i <= r ; i++)
	{
		printf(" %d",i);
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}