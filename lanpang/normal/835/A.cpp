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

int a , b , c , d , e , f , g;

int main ()
{
	cin >> a >> b >> c >> d >> e;
	f = a*b+2*d;
	g = a*c+2*e;
	if (f == g)
	{
		cout << "Friendship\n";
	}
	else
	{
		if (f < g)
		{
			cout << "First\n";
		}
		else
		{
			cout << "Second\n";
		}
	}
	//system("PAUSE");
	return 0;
}