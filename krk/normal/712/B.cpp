#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, R, U, D;
int res;

int main()
{
	char ch;
	while (scanf(" %c", &ch) == 1)
		if (ch == 'L') L++;
		else if (ch == 'R') R++;
		else if (ch == 'U') U++;
		else if (ch == 'D') D++;
	if (L < R) swap(L, R);
	if (U < D) swap(U, D);
	if ((L + R + U + D) % 2 != 0)
		printf("-1\n");
	else {
		if ((L + R) % 2 != 0) { res++; L--; D++; }
		res += (max(L, R) - min(L, R)) / 2;
		res += (max(U, D) - min(U, D)) / 2;
		printf("%d\n", res);
	}
	return 0;
}