#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int mod = 7;

int a, b;

int Read()
{
	string s; cin >> s;
	if (s == "monday") return 0;
	else if (s == "tuesday") return 1;
		else if (s == "wednesday") return 2;
			else if (s == "thursday") return 3;
				else if (s == "friday") return 4;
					else if (s == "saturday") return 5;
						else if (s == "sunday") return 6;
}

int main()
{
	a = Read(); b = Read();
	if ((a + 28) % mod == b || (a + 31) % mod == b || (a + 30) % mod == b)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}