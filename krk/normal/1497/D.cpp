#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 5005;

int T;
int n;
int tag[Maxn];
int s[Maxn];
ll best[Maxn];
int cur;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &tag[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		fill(best, best + n, -Inf);
		ll res = -Inf;
		for (int i = 0; i < n; i++) {
			ll mybest = 0;
			for (int j = i - 1; j >= 0; j--)
				if (tag[j] != tag[i]) {
					ll oldbest = best[j];
					best[j] = max(best[j], mybest + abs(s[j] - s[i]));
					mybest = max(mybest, oldbest + abs(s[j] - s[i]));
				}
			best[i] = max(best[i], mybest);
		}
		for (int i = 0; i < n; i++)
			res = max(res, best[i]);
		cout << res << endl;
	}
    return 0;
}