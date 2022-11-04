#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[300001] , ma , mi , s , p[2] , c[2];
int top=1 , next1[600001] , adj[600001] , to[600001];

void listing(int x , int y)
{
	to[top] = y;
	to[top+1] = x;
	next1[top] = adj[x];
	next1[top+1] = adj[y];
	adj[x] = top;
	adj[y] = top+1;
	top += 2;
}

int trying(int x , int h)
{
	int i , mm;
	c[0] = 0;
	c[1] = 0;
	mm = a[x];
	if (a[x] == ma)
	    c[0]++;
	if (a[x] == ma-1)
	    c[1]++;    
	if (h == 0)
	{
		for (i = adj[x] ; i != 0 ; i = next1[i])
		{
			mm = max(mm,a[to[i]]+1);
			if (a[to[i]] == ma)
			    c[0]++;
			if (a[to[i]] == ma-1)
			    c[1]++;    
		}
	}
		if (c[0] < p[0])
		    mm = ma+2;
		else
		{
			if (c[1] < p[1])
			    mm = ma+1;
		}    
		return mm;
}

int main ()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (i == 1)
		{
			ma = a[i];
		}
		else
		{
			if (a[i] > ma)
			{
				ma = a[i];
			}
		}
	}
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&j,&k);
		listing(j,k);
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == ma)
		    p[0]++;
		if (a[i] == ma-1)
		    p[1]++;    
	}
	mi = ma+2;
	for (i = 1 ; i <= n ; i++)
	{
			s = trying(i,0);
			if (s < mi)
			{
				mi = s;
			}
	}
	cout << mi << "\n";
	//system("PAUSE");
	return 0;
}