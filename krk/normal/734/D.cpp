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

const int Inf = 2000000007;

int val[8];
char cur[8];
int n, X, Y;

bool Check()
{
	for (int i = 0; i < 8; i++) {
		if (cur[i] == 'Q') return true;
		if (i % 2 == 0 && cur[i] == 'R') return true;
		if (i % 2 == 1 && cur[i] == 'B') return true;
	}
	return false;
}

int main() 
{
	val[0] = val[1] = val[2] = val[3] = Inf;
	val[4] = val[5] = val[6] = val[7] = -Inf;
	fill(cur, cur + 8, '?');
	scanf("%d", &n);
	scanf("%d %d", &X, &Y);
	for (int i = 0; i < n; i++) {
		char ch; int x, y; scanf(" %c %d %d", &ch, &x, &y);
		if (y == Y)
			if (X < x) {
				if (x < val[0]) val[0] = x, cur[0] = ch;
			} else {
				if (x > val[4]) val[4] = x, cur[4] = ch;
			}
		else if (x - y == X - Y)
			if (Y < y) {
				if (y < val[1]) val[1] = y, cur[1] = ch;
			} else {
				if (y > val[5]) val[5] = y, cur[5] = ch;
			}
		else if (x == X)
			if (Y < y) {
				if (y < val[2]) val[2] = y, cur[2] = ch;
			} else {
				if (y > val[6]) val[6] = y, cur[6] = ch;
			}
		else if (x + y == X + Y)
			if (Y < y) {
				if (y < val[3]) val[3] = y, cur[3] = ch;
			} else {
				if (y > val[7]) val[7] = y, cur[7] = ch;
			}
	}
	printf("%s\n", Check()? "YES": "NO");
    return 0;
}