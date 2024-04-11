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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m;
char a[maxn] , b[maxn];

int main()
{
	int i , t , f;
	cin >> n >> m;
	cin >> a+1;
	cin >> b+1;
	f = 0;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == '*')
		{
			f = 1;
			break;
		}
	}
	if (!f)
	{
		if (n != m) 
		{
			cout << "NO\n";
			return 0;
		}
		for (i = 1 ; i <= n ; i++)
		{
			if (a[i] != b[i])
			{
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
	}
	else
	{
		if (n > m+1)
		{
			cout << "NO\n";
			return 0;
		}
		t = 0;
		for (i = 1 ; i <= n ; i++) 
		{
			if (a[i] == '*') break;
			if (a[i] != b[i])
			{
				t = 1;
				break;
			}
		}
		for (i = n ; i >= 1 ; i--)
		{
			if (a[i] == '*') break;
			if (a[i] != b[m-n+i])
			{
				t = 1;
				break;
			}
		}
		if (t) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}