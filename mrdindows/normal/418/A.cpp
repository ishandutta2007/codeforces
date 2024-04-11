#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <bitset>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long ll;
const int size = 1007;
const ll modulo = 1000000007;
const int INF = 2e9;
const double EPS = 1e-6;
const double PI = acos(-1.0);

int a[size][size];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	if (k * 2 >= n || n < 3)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << n*k << endl;
	for (int i = 0; i < n; i++)
	{
		int rest = k;
		for (int j = 0; j < n; j++)
		{
			if (i != j && a[i][j] == 0 && rest > 0)
			{
				a[i][j] = a[j][i] = 1;
				--rest;
				printf("%d %d\n", i + 1, j + 1);
			}
		}
	}
	return 0;
}