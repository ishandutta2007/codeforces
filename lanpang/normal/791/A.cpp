#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a , b , i=0;

int main ()
{
	cin >> a >> b;
	while (a <= b)
	{
		i++;
		a *= 3;
		b *= 2;
	}
	cout << i << "\n";
	//system("PAUSE");
	return 0;
}