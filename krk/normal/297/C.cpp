#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 100005;

int n;
ii p[Maxn];
int a[Maxn], b[Maxn];
set <int> takena, takenb;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].first); p[i].second = i;
	}
	sort(p, p + n);
	int pa = Inf, pb = Inf;
	for (int i = n - 1; i >= 0; i--) if (p[i].first) {
		int st = (n - 1 - i) % 3;
		if (st == 0) {
			int cura = (p[i].first + 1) / 2, curb = p[i].first - cura;
			a[p[i].second] = cura; b[p[i].second] = curb;
			takena.insert(cura); takenb.insert(curb);
		} else if (st == 1) {
			pa = min(pa, p[i].first);
			while (takena.count(pa)) pa--;
			a[p[i].second] = pa; b[p[i].second] = p[i].first - pa;
			takena.insert(pa);
		} else {
			pb = min(pb, p[i].first);
			while (takenb.count(pb)) pb--;
			a[p[i].second] = p[i].first - pb; b[p[i].second] = pb;
			takenb.insert(pb);
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	for (int i = 0; i < n; i++)
		printf("%d%c", b[i], i + 1 < n? ' ': '\n');
	return 0;
}