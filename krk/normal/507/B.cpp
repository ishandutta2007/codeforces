#include <cstdio>
using namespace std;

typedef long long ll;

ll r;
ll X1, Y1, X2, Y2;
ll ds;

int main()
{
	scanf("%I64d", &r); r *= 2; r = r * r;
	scanf("%I64d %I64d %I64d %I64d", &X1, &Y1, &X2, &Y2);
	ds = ll(X1 - X2) * (X1 - X2) + ll(Y1 - Y2) * (Y1 - Y2);
	ll cur = 0;
	while (cur * cur * r < ds) cur++;
	printf("%I64d\n", cur);
	return 0;
}