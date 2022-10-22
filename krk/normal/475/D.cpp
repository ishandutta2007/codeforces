#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
int cur;
ii has[2][Maxn];
int len[2];
map <int, ll> M;
int q;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Add(ii p)
{
	if (p.second == 0) return;
	if (len[!cur] && has[!cur][len[!cur] - 1].first == p.first)
		has[!cur][len[!cur] - 1].second += p.second;
	else has[!cur][len[!cur]++] = p;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		Add(ii(a, 1));
	}
	cur = !cur;
	while (len[cur]) {
		len[!cur] = 0;
		ii p = has[cur][0];
		M[p.first] += p.second;
		Add(ii(p.first, p.second - 1));
		ii c;
		for (int i = 1; i < len[cur]; i++) {
			c = has[cur][i];
			Add(ii(gcd(p.first, c.first), 1));
			M[c.first] += c.second;
			Add(ii(c.first, c.second - 1));
			p = c;
		}
		cur = !cur;
	}
	scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x);
		printf("%I64d\n", M.find(x) != M.end()? M[x]: 0);
	}
	return 0;
}