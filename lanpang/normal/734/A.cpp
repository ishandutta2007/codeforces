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

int a , d , n , i;
char c;

int main ()
{
	cin >> n;
	c = getchar();
	for (i = 1 ; i <= n ; i++)
	{
		c = getchar();
		if (c == 'A')
		    a++;
		else
		    d++;    
	}
	if (a == d)
	{
		cout << "Friendship\n";
	}
	if (a > d)
	{
		cout << "Anton\n";
	}
	if (a < d)
	{
		cout << "Danik\n";
	}
	//system("PAUSE");
	return 0;
}