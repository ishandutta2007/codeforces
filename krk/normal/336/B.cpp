#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 100005;

int m, r;
ld sq = sqrt(2.0l);
ld sum;

int main()
{
	scanf("%d %d", &m, &r);
	sum += ld(m) * 2.0l;
	if (1 < m) sum += 2.0l * (m - 1) * (2.0l * 1.0l + sq);
	for (int i = 2; i < m; i++) sum += 2.0l * (m - i) * (2.0l * ld(i - 1) + 2.0l * sq);
	sum /= ld(ll(m) * ll(m));
	sum *= r;
	cout << fixed << setprecision(10) << sum << endl;
	return 0;
}