#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int a, b;
ll n;
int x;

void toPower(int a, ll p, int &pw, int &sum)
{
	if (p == 0) { pw = 1; sum = 0; }
	else {
		toPower(a, p / 2, pw, sum);
		if (p % 2 == 0) {
			sum = ll(sum) * (pw + 1) % mod;
			pw = ll(pw) * pw % mod;
		} else {
			sum = ll(sum) * (pw + 1) % mod;
			pw = ll(pw) * pw % mod;
			sum = (sum + pw) % mod;
			pw = ll(pw) * a % mod;
		}
	}
}

int main()
{
	scanf("%d %d %I64d %d", &a, &b, &n, &x);
	int pw, sum;
	toPower(a, n, pw, sum);
	printf("%d\n", int((ll(pw) * x + ll(sum) * b) % mod));
	return 0;
}