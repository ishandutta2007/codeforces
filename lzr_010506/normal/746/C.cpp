#include <bits/stdc++.h>
using namespace std;
int s, x1, x2, t1, t2, p, d;
int main()
{
	scanf("%d %d %d %d %d %d %d", &s, &x1, &x2, &t1, &t2, &p, &d);
	if(x1 > x2) x1 = s - x1, x2 = s - x2, d *= -1, p = s - p;
	p *= d;
	if(p > x1) p -= 2 * s;
	printf("%d\n", min((x2 - x1) * t2, (x2 - p) * t1));
	return 0;
}