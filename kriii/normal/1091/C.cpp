#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

set<long long> ans;
long long n;

void test(int g)
{
	long long u = n / g;
	long long c = u * (u - 1) / 2;
	ans.insert(c*g+u);
}

int main()
{
	scanf ("%lld",&n);

	for (int i=1;i*i<=n;i++) if (n % i == 0){
		test(i);
		test(n/i);
	}

	for (auto x : ans) printf ("%lld ",x);

	return 0;
}