#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef long long ll;

const int Maxn = 100005;
const ll Inf = 9000000000000000000ll;

int n, k;
vector <iii> byx, byy;
int tk[Maxn];
ll tot = Inf;
int res;

void Gen5(int X1, int Y1, int X2, int Y2)
{
	tot = min(tot, max(2ll, ll(Y2 - Y1)) * max(2ll, ll(X2 - X1)) / 4);
}

void Gen4(int X1, int Y1, int X2)
{
	int pnt = n - 1;
	while (res <= k && pnt >= 0) {
		Gen5(X1, Y1, X2, byy[pnt].first.first);
		if (tk[byy[pnt].second]++ == 0) res++;
		pnt--;
	}
	while (pnt < n - 1) {
		pnt++;
		if (--tk[byy[pnt].second] == 0) res--;
	}
}

void Gen3(int X1, int Y1)
{
	int pnt = n - 1;
	while (res <= k && pnt >= 0) {
		Gen4(X1, Y1, byx[pnt].first.first);
		if (tk[byx[pnt].second]++ == 0) res++;
		pnt--;
	}
	while (pnt < n - 1) {
		pnt++;
		if (--tk[byx[pnt].second] == 0) res--;
	}
}

void Gen2(int X1)
{
	int pnt = 0;
	while (res <= k && pnt < n) {
		Gen3(X1, byy[pnt].first.first);
		if (tk[byy[pnt].second]++ == 0) res++;
		pnt++;
	}
	while (pnt > 0) {
		pnt--;
		if (--tk[byy[pnt].second] == 0) res--;
	}
}

void Gen1()
{
	int pnt = 0;
	while (res <= k && pnt < n) {
		Gen2(byx[pnt].first.first);
		if (tk[byx[pnt].second]++ == 0) res++;
		pnt++;
	}
	while (pnt > 0) {
		pnt--;
		if (--tk[byx[pnt].second] == 0) res--;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int X1, Y1, X2, Y2; scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		byx.push_back(iii(ii(X1 + X2, Y1 + Y2), i));
		byy.push_back(iii(ii(Y1 + Y2, X1 + X2), i));
	}
	sort(byx.begin(), byx.end()); sort(byy.begin(), byy.end());
	Gen1();
	printf("%I64d\n", tot);
	return 0;
}