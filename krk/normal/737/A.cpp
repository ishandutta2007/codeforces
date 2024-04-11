#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k, s, t;
int c[Maxn], v[Maxn];
vector <int> un, dif;
ll sum[Maxn];
int bi;

int main()
{
	scanf("%d %d %d %d", &n, &k, &s, &t);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &c[i], &v[i]);
	un.push_back(0); un.push_back(s);
	for (int i = 0; i < k; i++) {
		int x; scanf("%d", &x);
		un.push_back(x);
	}
	sort(un.begin(), un.end());
	int tim = t - s;
	if (tim < 0) { printf("-1\n"); return 0; }
	for (int i = 0; i + 1 < un.size(); i++)
		dif.push_back(2 * (un[i + 1] - un[i]));
	sort(dif.begin(), dif.end());
	sum[dif.size()] = 0;
	for (int i = int(dif.size()) - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + dif[i];
	int bi = -1;
	for (int i = 0; i < n; i++)
		if (v[i] >= dif.back() / 2 && (bi == -1 || c[i] < c[bi])) {
			int ind = upper_bound(dif.begin(), dif.end(), v[i]) - dif.begin();
			ll nd = sum[ind] - ll(dif.size() - ind) * v[i];
			if (nd <= tim) bi = i;
		}
	printf("%d\n", bi == -1? -1: c[bi]);
	return 0;
}