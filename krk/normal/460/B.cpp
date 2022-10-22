#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int a, b, c;
vector <int> res;

int dSum(ll x)
{
	int res = 0;
	while (x) { res += x % 10; x /= 10; }
	return res;
}

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	for (int s = 1; s <= 81; s++) {
		ll num = 1;
		for (int i = 0; i < a; i++)
			num *= s;
		num = num * b + c;
		if (num > 0 && num < 1000000000 && dSum(num) == s)
			res.push_back(num);
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}