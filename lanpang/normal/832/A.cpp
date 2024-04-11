#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

long long a , b;

int main ()
{
	cin >> a >> b;
	if ((a/b)%2)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	//system("PAUSE");
	return 0;
}