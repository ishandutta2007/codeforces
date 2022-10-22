#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int q;
ll x;

ll Solve(ll n, ll x)
{
	if (x % 2) return x / 2 + 1;
	if (n % 2)
		if (x == 2) return (n + 1) / 2 + Solve(n / 2, n / 2);
		else return (n + 1) / 2 + Solve(n / 2, x / 2 - 1);
	else return (n + 1) / 2 + Solve(n / 2, x / 2);
}

int main()
{
	scanf("%I64d", &n); 
	scanf("%d", &q); 
	while (q--) {
		scanf("%I64d", &x); 
		printf("%I64d\n", Solve(n, x));
	}
	return 0;
}