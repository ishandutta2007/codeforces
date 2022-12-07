#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;
bool B[1100][1100];
int n,m;

bool verifica(int i, int j)
{
	bool v = false;
	if (i >= 1 && j >= 1)
	{
		if (B[i-1][j-1] && B[i-1][j] && B[i][j-1])
		{
			v = true;
			return v;
		}
	}
	if (i >= 1 && j < m-1)
	{
		if (B[i-1][j+1] && B[i-1][j] && B[i][j+1])
		{
			v = true;
			return v;
		}
	}
	if (i < n-1 && j >= 1)
	{
		if (B[i+1][j-1] && B[i+1][j] && B[i][j-1])
		{
			v = true;
			return v;
		}
	}
	if (i < n-1 && j < m-1)
	{
		if (B[i+1][j+1] && B[i+1][j] && B[i][j+1])
		{
			v = true;
			return v;
		}
	}
	return v;
}

int main()
{
	int k,a,b;
	cin >> n >> m >> k;
	bool vv = false;
	int p = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		if (vv)
			continue;
		B[a-1][b-1] = true;
		vv = verifica(a-1,b-1);
		if (vv)
			p = i+1;
	}
	cout << p << endl;

	return 0;
}