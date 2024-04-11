#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

map<long long, pair<long long, long long> > chk;

pair<long long, long long> get(long long x)
{
	if (x < 8) return make_pair(x,x);
	if (chk.count(x)) return chk[x];
	long long m = 1;
	while (m * m * m <= x) m++; m--;

	pair<long long, long long> &res = chk[x];
	auto u = get(x - m * m * m);
	u.first++; u.second += m * m * m;
	if (res < u) res = u;
	auto v = get(m * m * m - (m - 1) * (m - 1) * (m - 1) - 1);
	v.first++; v.second += (m - 1) * (m - 1) * (m - 1);
	if (res < v) res = v;
	return res;
}

int main()
{
	long long x;
	scanf ("%lld",&x);
	auto p = get(x);
	printf ("%lld %lld\n",p.first,p.second);

	return 0;
}