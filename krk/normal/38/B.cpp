#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
int ways;

int main()
{
	cin >> a;
	cin >> b;
	for (char r = 'a'; r <= 'h'; r++)
		for (char c = '1'; c <= '8'; c++)
			if (r != a[0] && c != a[1] && !(abs(r - a[0]) == 2 && abs(c - a[1]) == 1 || abs(r - a[0]) == 1 && abs(c - a[1]) == 2) && 
				!(abs(r - b[0]) == 2 && abs(c - b[1]) == 1 || abs(r - b[0]) == 1 && abs(c - b[1]) == 2 || r == b[0] && c == b[1]))
			ways++;
	printf("%d\n", ways);
	return 0;
}