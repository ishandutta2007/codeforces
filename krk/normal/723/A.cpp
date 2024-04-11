#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 3;

int x[Maxd];

int main()
{
	for (int i = 0; i < Maxd; i++)
		cin >> x[i];
	sort(x, x + Maxd);
	int res = x[1] - x[0] + x[2] - x[1];
	printf("%d\n", res);
	return 0;
}