#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 50005;

int n;
ii lp[Maxn];
ld nlsum;
ld res;

bool Less(const ii &a, const ii &b)
{
	return a.first * ld(a.second) / 100.0l * (1.0l - ld(b.second) / 100.0l) > b.first * ld(b.second) / 100.0l * (1.0 - ld(a.second) / 100.0l);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &lp[i].first, &lp[i].second);
	sort(lp, lp + n, Less);
	for (int i = n - 1; i >= 0; i--) {
		res += ld(lp[i].first) * (1.0l + ld(lp[i].second) / 100.0l * nlsum);
		nlsum += 1.0l - ld(lp[i].second) / 100.0l;
	}
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}