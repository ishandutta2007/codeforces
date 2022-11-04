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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , k , a[maxn] , s[maxn] , x[maxn] , y[maxn] , q[maxn] , top , f[maxn] , h , ff[maxn];
vector<int> v[maxn];

int main()
{
	int i , j , t;
	cin >> n >> m >> k;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].push_back(i);
		v[y[i]].push_back(i);
		s[x[i]]++;
		s[y[i]]++;
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (s[i] < k)
		{
			f[i] = 1;
			q[++top] = i;
		}
	}
	for (i = m ; i >= 1 ; i--)
	{
		while (h < top)
		{
			h++;
			for (j = 0 ; j < v[q[h]].size() ; j++)
			{
				t = v[q[h]][j];
				if (!ff[t]) 
				{
					ff[t] = 1;
					s[x[t]]--;
					s[y[t]]--;
					if (!f[x[t]] && s[x[t]] < k)
					{
						f[x[t]] = 1;
						q[++top] = x[t];
					}
					if (!f[y[t]] && s[y[t]] < k)
					{
						f[y[t]] = 1;
						q[++top] = y[t];
					}
				}
			}
		}
		a[i] = n-top;
		if (!ff[i]) 
		{
			ff[i] = 1;
			s[x[i]]--;
			s[y[i]]--;
			if (!f[x[i]] && s[x[i]] < k) 
			{
				f[x[i]] = 1;
				q[++top] = x[i];
			}
			if (!f[y[i]] && s[y[i]] < k) 
			{
				f[y[i]] = 1;
				q[++top] = y[i];
			}
		}
	}
	for (i = 1 ; i <= m ; i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}