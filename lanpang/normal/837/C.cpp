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

int n , a , b , x[101] , y[101] , ma; 

int check1(int i , int j)
{
	int x1 = x[i] , y1 = y[i] , x2 = x[j] , y2 = y[j] , m;
	m = x1*y1+x2*y2;
	if (x1+x2 <= a)
	{
		if (max(y1,y2) <= b)
		{
			return m;
		}
	}
	if (max(x1,x2) <= a)
	{
		if (y1+y2 <= b)
		{
			return m;
		}
	}
	if (x1+y2 <= a)
	{
		if (max(y1,x2) <= b)
		{
			return m;
		}
	}
	if (max(x1,y2) <= a)
	{
		if (y1+x2 <= b)
		{
			return m;
		}
	}
	swap(a,b);
	if (x1+x2 <= a)
	{
		if (max(y1,y2) <= b)
		{
			return m;
		}
	}
	if (max(x1,x2) <= a)
	{
		if (y1+y2 <= b)
		{
			return m;
		}
	}
	if (x1+y2 <= a)
	{
		if (max(y1,x2) <= b)
		{
			return m;
		}
	}
	if (max(x1,y2) <= a)
	{
		if (y1+x2 <= b)
		{
			return m;
		}
	}
	return 0;
}

int main ()
{
	int i , j;
	cin >> n >> a >> b;
	for (i = 1 ; i <= n ; i++)
		cin >> x[i] >> y[i];
	for (i = 1 ; i < n ; i++)
	{
		for (j = i+1 ; j <= n ; j++)
		{
			ma = max(ma,check1(i,j));
		}
	}
	cout << ma << "\n";
	//system("PAUSE");
	return 0;
}