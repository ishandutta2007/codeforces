#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 300005;

int n;
int a[Maxn];
int bef[Maxn], nxt[Maxn];
int best;
vector <int> res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		bef[i] = i - 1;
		while (bef[i] && a[bef[i]] % a[i] == 0) bef[i] = bef[bef[i]];
	}
	for (int i = n; i >= 1; i--) {
		nxt[i] = i + 1;
		while (nxt[i] <= n && a[nxt[i]] % a[i] == 0) nxt[i] = nxt[nxt[i]];
	}
	for (int i = 1; i <= n; i++) {
		int val = nxt[i] - bef[i] - 2;
		if (val > best) { best = val; res.clear(); }
		if (val == best) res.push_back(bef[i] + 1);
	}
	sort(res.begin(), res.end()); res.erase(unique(res.begin(), res.end()), res.end());
	printf("%d %d\n", res.size(), best);
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}