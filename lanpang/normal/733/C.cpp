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

struct oper{
	int p , d;
}c[510];
int n , a[510] , m , b[510] , k;

bool check(int x , int y , int z)
{
	if (x == y) return true;
	int i , ma=0 , p=0 , d;
	for (i = x ; i <= y ; i++) ma = max(ma,a[i]);
	for (i = x ; i <= y ; i++)
	{
		if (i < y && a[i] == ma && a[i+1] < ma) 
		{
			p = i;
			d = 1;
		}
		if (i > x && a[i] == ma && a[i-1] < ma) 
		{
			p = i;
			d = 0;
		}
		if (p > 0) break;
	}
	if (p == 0) return false; 
	if (d == 0)
	{
		for (i = p ; i > x ; i--)
		{
			k++;
			c[k].p = i-x+z;
			c[k].d = 0;
		}
		for (i = p+1 ; i <= y ; i++)
		{
			k++;
			c[k].p = z;
			c[k].d = 1;
		}
	}
	else
	{
		for (i = p ; i < y ; i++)
		{
			k++;
			c[k].p = p-x+z;
			c[k].d = 1;
		}
		for (i = p ; i > x ; i--)
		{
			k++;
			c[k].p = i-x+z;
			c[k].d = 0;
		}
	}
	return true;
}

int main()
{
	int i , j , s , t;
	cin >> n;
	for (i = 1 ; i <= n ; i++) cin >> a[i];
	cin >> m;
	for (i = 1 ; i <= m ; i++) cin >> b[i];
	t = 1;
	for (i = 1 ; i <= n ; i++)
	{
		if (t > m)
		{
			cout << "NO\n";
			return 0;
		}
		s = 0;
		for (j = i ; j <= n ; j++)
		{
			s += a[j];
			if (s == b[t])
			{
				if (!check(i,j,t))
				{
					cout << "NO\n";
					return 0;
				}
				t++;
				break;
			}
			if (s > b[t])
			{
				cout << "NO\n";
				return 0;
			}
		}
		i = j;
	}
	if (t <= m)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (i = 1 ; i <= k ; i++)
	{
		cout << c[i].p << " ";
		if (c[i].d == 0) cout << "L\n";
		else cout << "R\n";
	}
	return 0;
}