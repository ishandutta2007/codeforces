#include <bits/stdc++.h>
using namespace std;
int main() 
{
	double a,b,c,D;
	scanf("%lf%lf%lf",&a,&b,&c);
	D = b * b - 4 * a * c;
	if(!a && !b && !c) printf("-1\n");
	else if(a == 0 && b == 0 && c != 0) printf("0\n");
	else if(a == 0) printf("1\n%lf\n", - c /b);
	else if(D < 0) printf("0\n");
	else if(D == 0) printf("1\n%.9lf\n", - b * 1.0 / 2.0 / a);
	else if(a > 0) printf("2\n%.9lf\n%.9lf\n", (- b - sqrt(D)) * 1.0 / 2.0 / a, (-b + sqrt(D)) * 1.0 / 2.0 / a);
	else printf("2\n%.9lf\n%.9lf\n",(- b + sqrt(D)) *1.0 / 2.0 / a,(- b - sqrt(D)) * 1.0 / 2.0 / a);

	return 0;
}