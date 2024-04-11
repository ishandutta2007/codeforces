#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
ii p[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i].first);
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i].second);
		sort(p, p + n);
		ll res = 0;
		for (int i = 0; i < n; i++) {
			ii cur = i > 0? p[i - 1]: ii(1, 1);
			if (cur == p[i]) ;
			else {
				if ((cur.first + cur.second) % 2 == 0)
					if (cur.second - cur.first == p[i].second - p[i].first) {
						res += p[i].second - cur.second;
						continue;
					} else cur.first++;
				int sk = p[i].second - cur.second;
				cur.first += sk; cur.second += sk;
				res += (p[i].first + 1 - cur.first) / 2;
			}
		}
		printf("%I64d\n", res);
	}
    return 0;
}