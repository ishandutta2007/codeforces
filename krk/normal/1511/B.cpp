#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &a, &b, &c);
		bool flag = a >= b;
		int resA = 1, resB = 1, resC = 1;
		while (a > 1) { resA *= 10; a--; }
		while (b > 1) { resB *= 10; b--; }
		while (c > 1) { resC *= 10; c--; }
		if (flag) resA += resC;
		else resB += resC;
		printf("%d %d\n", resA, resB);
	}
    return 0;
}