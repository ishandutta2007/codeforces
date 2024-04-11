#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, m;
ll x;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %I64d", &n, &m, &x);
		x--;
		ll col = x / n;
		ll row = x % n;
		x = row * m + col + 1;
		printf("%I64d\n", x); 
	}
    return 0;
}