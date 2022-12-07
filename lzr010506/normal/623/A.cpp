#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
ll a[505][505], w[505], color[505];
vector <ll> f;
int main()
{
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
		w[x]++;
		w[y]++;
	}
	for (i = 1; i <= n; i++)
	if (w[i] == n-1)
		color[i] = 2;
	for (i = 1; i <= n; i++)
	if (color[i] != 2)
	{
			ll flaga = 0, flagc = 0;
			for (j = 1; j <= n; j++)
			if (i != j)
			{
				if (color[j] == 1 && a[i][j] == 1)
					flaga = 1;
				else
				if (color[j] == 1 && a[i][j] == 0)
					flagc = 1;
				else
				if (color[j] == 3 && a[i][j] == 1)
					flagc = 1;
				else
				if (color[j] == 3 && a[i][j] == 0)
					flaga = 1;
			}
			if (flaga && flagc)
			{
				cout << "No" << endl;
				return 0;
			}
			if (flagc)
			{
				if (color[i] == 1)
				{
					cout << "No" << endl;
					return 0;
				}
				color[i] = 3;
			} 
			else
			if (flaga)
			{
				if (color[i] == 3)
				{
					cout << "No" << endl;
					return 0;
				}
				color[i] = 1;
			} 
			else
				if (color[i] == 0)
					color[i] = 1;
	}
	cout << "Yes" << endl;
	for (i = 1; i <= n; i++)
		cout << (char)(color[i] - 1 + 'a');
	cout << endl;
	return 0;
}