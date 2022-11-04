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

int n , a[510][510];
char c[10];

int main()
{
	int i , j;
	cin >> n;
	i = j = 1;
	while (i+j <= n)
	{
		a[i][j] = 1;
		if (j < n)
		{
			cout << "? " << i << " " << j+1 << " " << n << " " << n << "\n";
			fflush(stdout);
			cin >> c;
			if (c[0] == 'Y') j++;
			else i++;
		} 
		else i++;
	}
	a[i][j] = 1;
	i = j = n;
	while (i+j > n+2)
	{
		a[i][j] = 1;
		if (i > 1)
		{
			cout << "? 1 1 " << i-1 << " " << j << "\n";
			fflush(stdout);
			cin >> c;
			if (c[0] == 'Y') i--;
			else j--;
		}
		else j--;
	}
	a[i][j] = 1;
	cout << "! ";
	i = j = 1;
	while (i+j < n+n)
	{
		if (j < n && a[i][j+1]) 
		{
			cout << "R";
			j++;
		}
		else 
		{
			cout << "D";
			i++;
		}
	}
	cout << "\n";
	return 0;
}