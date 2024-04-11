#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int n;
int a[Maxn];
int mn[Maxn][2], mx[Maxn][2];
set <iii> S;
ll tot;

void UpdMn(int mn[], int val)
{
	if (val < mn[0]) mn[1] = mn[0], mn[0] = val;
	else if (val < mn[1]) mn[1] = val;
}

void UpdMx(int mx[], int val)
{
	if (val > mx[0]) mx[1] = mx[0], mx[0] = val;
	else if (val > mx[1]) mx[1] = val;
}

ll F(int x, int y, int fir)
{
	if (x > y) return 0ll;
	if (y < n) {
		set <iii>::iterator it2 = S.lower_bound(iii(ii(y + 2, 0), 0));
		it2--;
		if (it2->first.first != y + 1) {
			S.insert(iii(ii(it2->first.first, y), it2->second));
			S.insert(iii(ii(y + 1, it2->first.second), it2->second));
			S.erase(it2);
		}
	}
	set <iii>::iterator it = S.lower_bound(iii(ii(x + 1, 0), 0));
	it--;
	if (fir <= it->second) return 0;
	if (it->first.first != x) {
		S.insert(iii(ii(it->first.first, x - 1), it->second));
		S.insert(iii(ii(x, it->first.second), it->second));
		S.erase(it);
		it = S.lower_bound(iii(ii(x, 0), 0));
	}
	ll res = 0ll;
	int r = x;
	for (; it != S.end() && it->first.first <= y; )
		if (fir <= it->second) break;
		else {
			r = it->first.second;
			res += ll(fir - it->second) * (it->first.second - it->first.first + 1);
			S.erase(it++);
		}
	S.insert(iii(ii(x, r), fir));
	return res;
}

ll Get(int x)
{
	int mymn[2] = {n + 1, n + 1}, mymx[2] = {0, 0};
	for (int i = x; i < Maxn; i += x)
		for (int j = 0; j < 2; j++) {
			UpdMn(mymn, mn[i][j]);
			UpdMx(mymx, mx[i][j]);
		}
	if (mymx[0] <= mymn[0]) return 0;
	ll res = F(mymn[1] + 1, n, n + 1);
	res += F(mymn[0] + 1, mymn[1], mymx[0]);
	res += F(1, mymn[0], mymx[1]);
	return res;
}

int main()
{
	scanf("%d", &n);
	if (n == 1) { printf("0\n"); return 0; }
	for (int i = 0; i < Maxn; i++) {
		mn[i][0] = mn[i][1] = n + 1;
		mx[i][0] = mx[i][1] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		UpdMn(mn[a[i]], i);
		UpdMx(mx[a[i]], i);
	}
	for (int i = 1; i <= n; i++)
		S.insert(iii(ii(i, i), i));
	for (int i = Maxn - 1; i >= 1; i--)
		tot += ll(i) * Get(i);
	printf("%I64d\n", tot);
	return 0;
}