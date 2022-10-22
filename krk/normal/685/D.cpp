#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxn = 200005;
const int lim = 1000000001;

int n, k;
int x[Maxn], y[Maxn];
vector <int> un;
int has[Maxn];
vector <iiii> V;
ll res[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		un.push_back(x[i] - k + 1); un.push_back(x[i] + 1);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		int l = lower_bound(un.begin(), un.end(), x[i] - k + 1) - un.begin();
		int r = lower_bound(un.begin(), un.end(), x[i] + 1) - un.begin();
		V.push_back(iiii(ii(y[i] - k + 1, 1), ii(l, r)));
		V.push_back(iiii(ii(y[i] + 1, -1), ii(l, r)));
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		int l = V[i].second.first, r = V[i].second.second;
		int add = V[i].first.second;
		int y = V[i].first.first;
		for (int j = l; j < r; j++) {
			res[has[j]] -= ll(lim - y) * (un[j + 1] - un[j]);
			has[j] += add;
			res[has[j]] += ll(lim - y) * (un[j + 1] - un[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}