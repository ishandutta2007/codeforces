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

const int Maxn = 200015;
const int Maxm = 1048576;

int n;
ll t[Maxn], l[Maxn], r[Maxn];
vector <ll> un;
int cnt[Maxm];
int flag[Maxm];

void downOn(int v, int siz, int f)
{
	if (f == 0) {
		cnt[v] = 0;
		flag[v] = 0;
	} else if (f == 1) {
		cnt[v] = siz;
		flag[v] = 1;
	} else if (f == 2) {
		cnt[v] = siz - cnt[v];
		if (flag[v] == -1) flag[v] = 2;
		else flag[v] = 1 - flag[v]; 
	}
}

void Down(int v, int l, int m, int r)
{
	if (flag[v] != -1) {
		downOn(2 * v, m + 1 - l, flag[v]);
		downOn(2 * v + 1, r - m, flag[v]);
		flag[v] = -1;
	}
}

void Union(int v) { cnt[v] = cnt[2 * v] + cnt[2 * v + 1]; }

void Create(int v, int l, int r)
{
	flag[v] = -1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void Update(int v, int l, int r, int a, int b, int f)
{
	if (l == a && r == b) downOn(v, r - l + 1, f);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Update(2 * v, l, m, a, min(m, b), f);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, f);
		Union(v);
	}
}

int Get(int v, int l, int r)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (cnt[2 * v] < m + 1 - l) return Get(2 * v, l, m);
		else return Get(2 * v + 1, m + 1, r);
	}
}

int main()
{
	scanf("%d", &n);
	un.push_back(1);
	for (int i = 0; i < n; i++) {
		scanf("%I64d %I64d %I64d", &t[i], &l[i], &r[i]);
		un.push_back(l[i]); un.push_back(r[i] + 1ll);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	Create(1, 0, un.size() - 1);
	for (int i = 0; i < n; i++) {
		int a = lower_bound(un.begin(), un.end(), l[i]) - un.begin();
		int b = upper_bound(un.begin(), un.end(), r[i]) - un.begin() - 1;
		int fl;
		if (t[i] == 1) fl = 1;
		else if (t[i] == 2) fl = 0;
		else if (t[i] == 3) fl = 2;
		Update(1, 0, un.size() - 1, a, b, fl);
		int res = Get(1, 0, un.size() - 1);
		printf("%I64d\n", un[res]);
	}
	return 0;
}