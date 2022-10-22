#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int C, Hr, Hb, Wr, Wb;
ll res;

int main()
{
	scanf("%d %d %d %d %d", &C, &Hr, &Hb, &Wr, &Wb);
	if (Wb > Wr) { swap(Hr, Hb); swap(Wr, Wb); }
	if (ll(Wr) * Wr >= C)
		for (int i = 0, w = 0; w <= C; i++, w += Wr) {
			int j = (C - w) / Wb;
			res = max(res, ll(i) * Hr + ll(j) * Hb);
		}
	else {
		for (int i = 0, w = 0; i < Wb; i++, w += Wr) {
			int j = (C - w) / Wb;
			res = max(res, ll(i) * Hr + ll(j) * Hb);
		}
		for (int j = 0, w = 0; j < Wr; j++, w += Wb) {
			int i = (C - w) / Wr;
			res = max(res, ll(i) * Hr + ll(j) * Hb);
		}
	}
	printf("%I64d\n", res);
	return 0;
}