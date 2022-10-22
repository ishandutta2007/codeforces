#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 2000000000000000000ll;

ll a, b, c;
vector <ll> pol;
int res;

ll Mult(ll a, ll b)
{
	if (a <= Inf / b) return a * b;
	return Inf;
}

ll Add(ll a, ll b)
{
	return min(a + b, Inf);
}

int main()
{
	scanf("%I64d %I64d %I64d", &a, &b, &c);
	if (b == 1)
		if (c != 1) printf("0\n");
		else printf("%s\n", a == 1? "inf": "1");
	else {
		res += b == c;
		if (a == 1) {
			ll cur = b;
			while (cur < Inf) {
				res += c == Mult(b, cur);
				cur = Mult(cur, b);
			}
		}
		while (c) {
			pol.push_back(c % b);
			c /= b;
		}
		ll cur = 0;
		for (int i = pol.size() - 1; i >= 0; i--)
			cur = Add(Mult(cur, a), pol[i]);
		res += b == cur;
		printf("%d\n", res);
	}
	return 0;
}