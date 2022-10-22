#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 200005;

int n, m;
vector <int> dv;
vector <vector <int> > my;
vector <int> dp, par;
bool forb[Maxm];
vector <int> res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void gcd(int a, int &x, int b, int &y)
{
	if (a == 0) { x = 0; y = 1; }
	else {
		int xx, yy; gcd(b % a, xx, a, yy);
		x = yy - b / a * xx; y = xx;
	}
}

int Inv(int a, int b)
{
	int x, y; gcd(a, x, b, y);
	x %= b;
	if (x < 0) x += b;
	return x;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i * i <= m; i++)
		if (m % i == 0) {
			dv.push_back(i);
			if (i * i != m) dv.push_back(m / i);
		}
	sort(dv.begin(), dv.end());
	my.resize(dv.size(), vector <int>());
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		forb[a] = true;
	}
	for (int i = 0; i < m; i++) if (!forb[i]) {
		int g = gcd(i, m);
		int ind = lower_bound(dv.begin(), dv.end(), m / g) - dv.begin();
		my[ind].push_back(i);
	}
	dp.resize(dv.size(), 0); par.resize(dv.size(), 0);
	for (int i = 0; i < dv.size(); i++) {
		dp[i] = my[i].size(); par[i] = -1;
		for (int j = 0; j < i; j++) if (dv[i] % dv[j] == 0)
			if (dp[j] + my[i].size() > dp[i]) {
				dp[i] = dp[j] + my[i].size();
				par[i] = j;
			}
	}
	printf("%d\n", dp.back());
	int cur = dv.size() - 1;
	int lst = 1;
	while (cur >= 0) {
		for (int i = 0; i < my[cur].size(); i++) {
			int g = gcd(lst, m);
			int d = Inv(lst / g, m / g);
			res.push_back(ll(my[cur][i] / g) * d % m);
			lst = my[cur][i];
		}
		cur = par[cur];
	}
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}