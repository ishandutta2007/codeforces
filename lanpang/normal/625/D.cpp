#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , b[maxn];
char c[maxn];

void jian(int x)
{
	int i;
	for (i = x ; i >= 1 ; i--)
	{
		a[i]--;
		if (a[i] < 0) a[i] += 10;
		else return;
	}
	return;
}

bool check(int l , int r)
{
	int t=0;
	if (l > r) return false;
	while (l <= r)
	{
		if (l < r && a[l] > 9 && !(a[l] == 10 && a[r] == 9))
		{
			jian(r-1);
			a[r] += 10;
		}
		if (a[l] == a[r]+1)
		{
			if (a[l] == 1 && t == 0) return false;
			a[l]--;
			a[l+1] += 10;
		}
		if (a[l] > 18 || a[l] != a[r]) return false;
		if (l == r)
		{
			if (a[l]%2) return false;
			b[l] = a[l]/2;
			break;
		}
		else
		{
			b[l] = min(9,a[l]);
			b[r] = a[l]-b[l];
			if (b[l] > 0) t = 1;
			l++;
			r--;
		}
	}
	if (b[1]) cout << b[1];
	for (int i = 2 ; i <= n ; i++)
	{
		printf("%d",b[i]);
	}
	cout << "\n";
	return true;
}

int main()
{
	int i;
	cin >> c;
	n = strlen(c);
	for (i = 0 ; i < n ; i++)
	{
		a[i+1] = c[i]-'0';
	}
	if (!check(1,n))
	{
		a[2] += a[1]*10;
		for (i = 1 ; i <= n ; i++)
		{
			b[i] = 0;
		}
		if (!check(2,n))
		{
			cout << "0\n";
		}
	}
	return 0;
}