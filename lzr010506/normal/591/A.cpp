#include <bits/stdc++.h>
using namespace std;

int main()
{
	double l, p, q;
	scanf("%lf%lf%lf",&l,&p,&q);
	printf("%.4lf",l / (p + q) * p);
	return 0;
}