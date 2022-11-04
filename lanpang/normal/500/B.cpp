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

int n;
char a;
int f[301] , g[301];
vector <int> q[301];

int getf(int x)
{
	if (f[x] == x)
	    return x;
	else
	{
		f[x] = getf(f[x]);
	    return f[x];    
	}
}

int main ()
{
	int i , j , fi , fj;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		f[i] = i;
		cin >> g[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		a = getchar();
		for (j = 1 ; j <= n ; j++)
		{
			a = getchar();
			if (a == '1')
			{
				fi = getf(i);
				fj = getf(j);
				if (fi != fj)
				{
					f[fi] = fj;
				}
			}
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		f[i] = getf(i);
	}
	for (i = 1 ; i <= n ; i++)
	{
		q[f[i]].push_back(g[i]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (q[i].size())
		{
			sort(q[i].begin(),q[i].end());
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		cout << q[f[i]].front();
		if (i < n)
		    cout << " ";
		else
		    cout << "\n";
		q[f[i]].erase(q[f[i]].begin());	    
	}
	//system("PAUSE");
	return 0;
}