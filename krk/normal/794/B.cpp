#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long double ld;

int n, h;

int main()
{
	cin >> n >> h;
	ld p = ld(h) / sqrt(ld(n));
	for (int i = 1; i <= n - 1; i++)
		printf("%.10lf%c", double(p * sqrt(ld(i))), i + 1 <= n - 1? ' ': '\n');
	return 0;
}