# include <iostream>
# include <cstdio>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	a = (a >= x) ? (a - x) / 2 : a - x;
	b = (b >= y) ? (b - y) / 2 : b - y;
	c = (c >= z) ? (c - z) / 2 : c - z;
	if(a + b + c >= 0) puts("Yes");
	else puts("No");
	return 0;
}