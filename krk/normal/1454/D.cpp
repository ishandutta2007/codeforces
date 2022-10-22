#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 10005;

int T;
ll n;
vector <ill> V;
ll res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		V.clear();
		for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
			int t = 0;
			while (n % i == 0) {
				n /= i;
				t++;
			}
			V.push_back(ill(t, i));
		}
		if (n > 1) V.push_back(ill(1, n));
		sort(V.begin(), V.end());
		int k = V.back().first;
		fill(res, res + k, 1);
		for (int i = 0; i < V.size(); i++)
			for (int j = 1; j <= V[i].first; j++)
				res[k - j] *= V[i].second;
		printf("%d\n", k);
		for (int i = 0; i < k; i++)
			printf("%I64d%c", res[i], i + 1 < k? ' ': '\n');
	}
    return 0;
}