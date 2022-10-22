#include <cstdio>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

typedef tuple <int, int, int> iii;

bool comp(iii l, iii r) {
    int ll = get<0>(l), lr = get<1>(l), rl = get<0>(r), rr = get<1>(r);
    if (ll == rl) {
        return lr > rr;
    } else return ll < rl;
}

int n;
iii segments[300005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d%d", &l, &r);
		segments[i] = iii(l, r, i);
	}
	sort(segments, segments + n, comp);
	int prevr = -1, previ = -1;
	for (int i = 0; i < n; i++) {
		int curr = get<1>(segments[i]);
		int curi = get<2>(segments[i]);
		if (curr > prevr) {
			prevr = curr;
			previ = curi;
		}
		else {
			printf("%d %d\n", curi + 1, previ + 1);
			return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
}