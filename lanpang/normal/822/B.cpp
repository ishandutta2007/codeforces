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

char a[1001] , b[1001] , c;
int n , m , p , s=1001 , t , i , j;

int main ()
{
	cin >> n >> m;
	c = getchar();
	gets(a);
	gets(b);
	for (i = 0 ; i <= m-n ; i++)
	{
		t = 0;
		for (j = 0 ; j < n ; j++)
		{
			if (b[i+j] != a[j])
			{
				t++;
			}
		}
		if (t < s)
		{
			s = t;
			p = i;
		}
	}
	cout << s << "\n";
	t = 0;
	for (i = 0 ; i < n ; i++)
	{
		if (b[p+i] != a[i])
		{
			t++;
			if (t < s)
				cout << i+1 << " ";
			else
			    cout << i+1 << "\n";
		}
	}
	//system("PAUSE");
	return 0;
}