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

const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
int cnt[Maxm];
set <int> S[Maxn];
int BIT[Maxn];
ll res;

void Create(int v, int l, int r)
{
	if (l == r) cnt[v] = S[l].size();
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
	}
}

int getNext(int v, int l, int r, int val)
{
	cnt[v]--;
	if (l == r) {
		set <int>::iterator it = S[l].upper_bound(val);
		if (it == S[l].end()) it = S[l].begin();
		int res = *it;
		S[l].erase(it);
		return res;
	} else {
		int m = l + r >> 1;
		if (cnt[2 * v] > 0) return getNext(2 * v, l, m, val);
		else return getNext(2 * v + 1, m + 1, r, val);
	}
}

void Insert(int ind, int val)
{
	ind++;
	for (int i = ind; i <= n; i += i & -i)
		BIT[i] += val;
}

int Get(int ind)
{
	ind++;
	int res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int Get(int l, int r)
{
	return Get(r) - Get(l - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		S[a[i]].insert(i);
		Insert(i, 1);
	}
	Create(1, 1, Maxn - 1);
	int cur = n - 1;
	for (int i = 0; i < n; i++) {
		int a = getNext(1, 1, Maxn - 1, cur);
		if (cur < a) res += Get(cur + 1, a);
		else res += Get(cur + 1, n - 1) + Get(0, a);
		cur = a; Insert(a, -1);
	}
	printf("%I64d\n", res);
	return 0;
}