#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;

int n, m;
vector <int> neigh[Maxn];
int col[Maxn];
int cnt1, cnt2;
vector <ii> inf;
ll res;

bool canColour(int v, int &siz, int &a, int &b, int c = 1)
{
	if (col[v]) return col[v] == c;
	col[v] = c; siz++; a++;
	for (int i = 0; i < neigh[v].size(); i++)
		if (!canColour(neigh[v][i], siz, b, a, -c))
			return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!col[i]) {
		int siz = 0, a = 0, b = 0;
		if (canColour(i, siz, a, b)) {
			if (siz == 1) cnt1++;
			else if (siz == 2) cnt2++;
			else inf.push_back(ii(a, b));
		} else { printf("0 1\n"); return 0; }
	}
	if (!inf.empty()) {
		printf("1 ");
		for (int i = 0; i < inf.size(); i++)
			res += ll(inf[i].first) * (inf[i].first - 1) / 2 + ll(inf[i].second) * (inf[i].second - 1) / 2;
		printf("%I64d\n", res);
	} else if (cnt2) {
		printf("2 ");
		res = ll(cnt2) * (cnt2 - 1) * 2 + ll(cnt1) * cnt2;
		printf("%I64d\n", res);
	} else printf("3 %I64d\n", ll(cnt1) * (cnt1 - 1) * (cnt1 - 2) / 6);
	return 0;
}