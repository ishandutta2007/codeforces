#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ld, int> ldi;

const int Maxn = 2005;

int n;
ii xy[Maxn];
ldi srt[Maxn];
int slen;
ll res;

ll Dot(ll ax, ll ay, ll bx, ll by) { return ax * bx + ay * by; }

ll Lens(ll ax, ll ay) { return ax * ax + ay * ay; }

bool Check(const ii &A, const ii &B, const ii &C)
{
	int ax = B.first - A.first, ay = B.second - A.second;
	int bx = C.first - A.first, by = C.second - A.second;
	ll d = Dot(ax, ay, bx, by);
	return d * d == Lens(ax, ay) * Lens(bx, by);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &xy[i].first, &xy[i].second);
	for (int i = 0; i < n; i++) {
		slen = 0;
		for (int j = 0; j < n; j++) if (i != j)
			srt[slen++] = ldi(atan2(ld(xy[j].second - xy[i].second), ld(xy[j].first - xy[i].first)), j);
		sort(srt, srt + slen);
		int pnt = 0;
		while (pnt < slen && xy[srt[pnt].second] <= xy[i]) pnt++;
		int cur = 0;
		while (pnt < slen && xy[i] < xy[srt[pnt].second]) {
			int j = pnt;
			while (j < slen && xy[i] < xy[srt[j].second] && Check(xy[i], xy[srt[pnt].second], xy[srt[j].second])) j++;
			res += ll(j - pnt) * cur; cur += j - pnt;
			pnt = j;
		}
	}
	printf("%I64d\n", res);
	return 0;
}