#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 3;

int x[Maxd], y[Maxd];
set <ii> S;

ii F(int a, int b, int c)
{
	int ax = x[b] - x[a], ay = y[b] - y[a];
	int bx = x[c] - x[a], by = y[c] - y[a];
	int cx = ax + bx, cy = ay + by;
	return ii(x[a] + cx, y[a] + cy);
}

int main()
{
	for (int i = 0; i < Maxd; i++)
		scanf("%d %d", &x[i], &y[i]);
	S.insert(F(0, 1, 2));
	S.insert(F(1, 0, 2));
	S.insert(F(2, 0, 1));
	printf("%d\n", S.size());
	for (set <ii>::iterator it = S.begin(); it != S.end(); it++)
		printf("%d %d\n", it->first, it->second);
	return 0;
}