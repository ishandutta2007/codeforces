#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxd = 6;
const ii dr[Maxd] = {{1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}};

int T;
int x, y;
int cost[Maxd];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &x, &y);
		for (int i = 0; i < Maxd; i++)
			scanf("%d", &cost[i]);
		for (int i = 0; i < Maxd; i++)
			for (int a = 0; a < Maxd; a++)
				for (int b = 0; b < Maxd; b++)
					for (int c = 0; c < Maxd; c++)
						if (dr[a].first + dr[b].first == dr[c].first &&
							dr[a].second + dr[b].second == dr[c].second)
							cost[c] = min(cost[c], cost[a] + cost[b]);
		ll res = 0;
		if (x > 0 && y > 0) {
			int tk = min(x, y);
			res += ll(tk) * cost[0];
			x -= tk; y -= tk;
		}
		if (x < 0 && y < 0) {
			int tk = min(-x, -y);
			res += ll(tk) * cost[3];
			x += tk; y += tk;
		}
		if (x > 0)
			res += ll(x) * cost[5];
		if (x < 0)
			res += ll(-x) * cost[2];
		if (y > 0)
			res += ll(y) * cost[1];
		if (y < 0)
			res += ll(-y) * cost[4];
		printf("%I64d\n", res);
	}
    return 0;
}