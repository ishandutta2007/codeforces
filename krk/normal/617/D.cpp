#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int ax, ay;
int bx, by;
int cx, cy;

bool Check(int ax, int ay, int bx, int by, int cx, int cy)
{
	if (min(bx, cx) <= ax && ax <= max(bx, cx) && min(by, cy) <= ay && ay <= max(by, cy))
		return ax == bx || ax == cx || ay == by || ay == cy;
	return false;
}

int main() 
{
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
	if (ax == bx && bx == cx || ay == by && by == cy) printf("1\n");
	else if (Check(ax, ay, bx, by, cx, cy) || Check(bx, by, ax, ay, cx, cy) || Check(cx, cy, ax, ay, bx, by)) printf("2\n");
	else printf("3\n");
    return 0;
}