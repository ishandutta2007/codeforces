#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;
typedef pair <ld, ii> ldii;
typedef long long ll;

const int Maxn = 1000000;

int n, c, d;
ldii arr[Maxn];
int rig1[Maxn], rig2[Maxn];
int lef1[Maxn], lef2[Maxn];
ll cur;
ll res;

bool Cross(int a, int b) { return ll(arr[a].second.first) * arr[b].second.second - 
								  ll(arr[b].second.first) * arr[a].second.second > 0; }

void Fix(int &a, int &b)
{
	while (a < 0) a += n, b += n;
	int tims = a / n;
	a -= tims * n; b -= tims * n;
}

int Get(int a1, int b1, int a2, int b2)
{
	Fix(a1, b1); Fix(a2, b2);
	int lef = max(a1, a2), rig = min(b1, b2);
	if (lef > rig) return 0;
	return rig - lef + 1;
}

int main()
{
	scanf("%d %d %d", &n, &c, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].second.first, &arr[i].second.second);
		arr[i].second.first -= c; arr[i].second.second -= d;
		arr[i].first = atan2(ld(arr[i].second.second), ld(arr[i].second.first));
	}
	sort(arr, arr + n);
	int lef = 0, rig = 0;
	for (int i = 0; i < n; i++) {
		lef--; rig--;
		if (lef <= 0) lef = 1;
		while (lef < n && !Cross(i, (i + lef) % n) && !Cross((i + lef) % n, i)) lef++;
		if (rig < lef) rig = lef;
		while (rig < n && Cross(i, (i + rig) % n)) rig++;
		if (lef == rig) rig1[i] = rig2[i] = -Maxn;
		else rig1[i] = lef, rig2[i] = rig - 1;
	}
	lef = 0, rig = 0;
	for (int i = n - 1; i >= 0; i--) {
		lef++; rig++;
		if (lef >= 0) lef = -1;
		while (lef > -n && !Cross(i, (i + lef + n) % n) && !Cross((i + lef + n) % n, i)) lef--;
		if (rig > lef) rig = lef;
		while (rig > -n && Cross((i + rig + n) % n, i)) rig--;
		if (lef == rig) lef1[i] = lef2[i] = -Maxn;
		else lef1[i] = rig + 1, lef2[i] = lef;
	}
	int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
	for (int i = 0; i < n; i++) {
		l1--; l2--; r1--; r2--;
		while (r1 <= 0 && r1 < r2) {
			int ind = (i + r1 + n) % n;
			if (rig1[ind] != -Maxn) {
				int mya = r1 + rig1[ind], myb = r1 + rig2[ind];
				cur -= Get(l1, l2 - 1, mya, myb);
			}
			r1++;
		}
		if (r1 == r2)
			while (r1 < n && (r1 <= 0 || !Cross(i, (i + r1) % n) && !Cross((i + r1) % n, i))) r1++, r2++;
		while (r2 < n && Cross(i, (i + r2) % n)) {
			int ind = (i + r2 + n) % n;
			if (rig2[ind] != -Maxn) {
				int mya = r2 + rig1[ind], myb = r2 + rig2[ind];
				cur += Get(l1, l2 - 1, mya, myb);
			}
			r2++;
		}

		while (l1 < l2 && (l1 <= 0 || !Cross((i + l1 + n) % n, i))) {
			int ind = (i + l1 + 2 * n) % n;
			if (lef1[ind] != -Maxn) {
				int mya = l1 + lef1[ind], myb = l1 + lef2[ind];
				cur -= Get(r1, r2 - 1, mya, myb);
			}
			l1++;
		} 
		if (l1 == l2)
			while (l1 < n && (l1 <= 0 || !Cross((i + l1 + n) % n, i))) l1++, l2++;

		while (l2 < n && Cross((i + l2 + n) % n, i)) {
			int ind = (i + l2 + n) % n;
			if (lef1[ind] != -Maxn) {
				int mya = l2 + lef1[ind], myb = l2 + lef2[ind];
				cur += Get(r1, r2 - 1, mya, myb);
			}
			l2++;
		}
		res += cur;
	}
	printf("%I64d\n", res / 3);
	return 0;
}