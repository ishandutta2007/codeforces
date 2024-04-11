#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 8;

string s;
int res;

int main()
{
	cin >> s;
	int r = s[0] - 'a', c = s[1] - '1';
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) if (i || j)
			if (0 <= r + i && r + i < Maxd && 0 <= c + j && c + j < Maxd)
				res++;
	printf("%d\n", res);
	return 0;
}