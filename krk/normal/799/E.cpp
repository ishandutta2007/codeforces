#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;
const int Maxm = 1048576;

int n, m, k;
int c[Maxn];
int tims[Maxn];
vector <int> A, B, C;
int cnt[Maxm];
ll sum[Maxm];
vector <int> un;
ll res = Inf;

void Update(int v, int l, int r, int x, int add)
{
	cnt[v] += add; sum[v] += ll(add) * un[x];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, add);
		else Update(2 * v + 1, m + 1, r, x, add);
	}
}

ll getSum(int v, int l, int r, int nd)
{
	if (nd <= 0) return 0;
	if (l == r) return ll(un[l]) * nd;
	else {
		int m = l + r >> 1;
		if (nd <= cnt[2 * v]) return getSum(2 * v, l, m, nd);
		else return sum[2 * v] + getSum(2 * v + 1, m + 1, r, nd - cnt[2 * v]);
	}
}

int getInd(int val)
{
	return lower_bound(un.begin(), un.end(), val) - un.begin();
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		un.push_back(c[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	int a; scanf("%d", &a);
	while (a--) {
		int x; scanf("%d", &x);
		tims[x] |= 1;
	}
	int b; scanf("%d", &b);
	while (b--) {
		int x; scanf("%d", &x);
		tims[x] |= 2;
	}
	for (int i = 1; i <= n; i++)
		if (tims[i] == 0) Update(1, 0, un.size() - 1, getInd(c[i]), 1);
		else if (tims[i] == 1) A.push_back(c[i]);
			 else if (tims[i] == 2) B.push_back(c[i]);
			 else C.push_back(c[i]);
	sort(A.begin(), A.end()); sort(B.begin(), B.end()); sort(C.begin(), C.end());
	int my = min(A.size(), B.size());
	ll cur = 0;
	for (int i = 0; i < my; i++)
		cur += A[i] + B[i];
	for (int i = my; i < A.size(); i++)
		Update(1, 0, un.size() - 1, getInd(A[i]), 1);
	for (int i = my; i < B.size(); i++)
		Update(1, 0, un.size() - 1, getInd(B[i]), 1);
	int tk = k - my;
	for (int i = 0; i < C.size(); i++)
		if (i < tk) cur += C[i];
		else Update(1, 0, un.size() - 1, getInd(C[i]), 1);
	while (my >= 0) {
		int nd = m - my - my - max(0, k - my);
		if (k - my <= C.size() && 0 <= nd && nd <= cnt[1]) res = min(res, cur + getSum(1, 0, un.size() - 1, nd));
		if (my == 0) break;
		my--;
		cur -= (A[my] + B[my]);
		Update(1, 0, un.size() - 1, getInd(A[my]), 1); Update(1, 0, un.size() - 1, getInd(B[my]), 1);
		int ind = k - my - 1;
		if (0 <= ind && ind < C.size()) {
			Update(1, 0, un.size() - 1, getInd(C[ind]), -1);
			cur += C[ind];
		}
	}
	if (res >= Inf) printf("-1\n");
	else printf("%I64d\n", res);
	return 0;
}