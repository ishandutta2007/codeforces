#include <cstdio>
#include <iostream>

int Abs(int x) {return x > 0 ? x : -x;}

int main()
{
	int n, p, l, r; scanf("%d%d%d%d", &n, &p, &l, &r);
	if(l == 1 && r == n) puts("0");
	else if(l == 1) printf("%d\n", Abs(p - r) + 1);
	else if(r == n) printf("%d\n", Abs(p - l) + 1);
	else printf("%d\n", std::min(Abs(p - l), Abs(p - r)) + r - l + 2);
}