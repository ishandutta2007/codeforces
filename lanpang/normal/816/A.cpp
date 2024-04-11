#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a , b , t;
char c;

int mmp(int a , int b)
{
	int a1 , a2 , b1 , b2 , aa , bb;
	a1 = a/10;
	a2 = a%10;
	b1 = b/10;
	b2 = b%10;
	aa = b2*10+b1;
	bb = a2*10+a1;
	if (aa == a && bb == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main ()
{
	cin >> a >> c >> b;
	while (1)
	{
		if (mmp(a,b))
		{
			cout << t << "\n";
			break;
		}
		t++;
		b++;
		if (b == 60)
		{
			b = 0;
			a++;
			if (a == 24)
			{
				a = 0;
			}
		}
	}
	//system("PAUSE");
	return 0;
}