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

const int Maxn = 100005;
const int Maxm = 524288;

int cnt[Maxm];
bool flag[Maxm];
int n, s1, s2;
int a[Maxn];
vector <int> un;

void downOn(int v) { cnt[v] = 0; flag[v] = true; }

void Down(int v)
{
	if (flag[v]) {
		downOn(2 * v); downOn(2 * v + 1);
		flag[v] = false;
	}
}

void Union(int v)
{
	cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
}

void Remove(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) downOn(v);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Remove(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Remove(2 * v + 1, m + 1, r, max(m + 1, a), b);
		Union(v);
	}
}

void Insert(int v, int l, int r, int x)
{
	if (l == r) cnt[v] = 1;
	else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x);
		else Insert(2 * v + 1, m + 1, r, x);
		Union(v);
	}
}

int getInd(int x)
{
	return lower_bound(un.begin(), un.end(), x) - un.begin();
}

bool Check(int x)
{
	Remove(1, 0, int(un.size()) - 1, 0, int(un.size()) - 1);
	if (abs(un[s1] - un[s2]) > x) return false;
	if (abs(un[s1] - un[a[0]]) <= x) Insert(1, 0, int(un.size()) - 1, s1);
	if (abs(un[s2] - un[a[0]]) <= x) Insert(1, 0, int(un.size()) - 1, s2);
	if (cnt[1] == 0) return false;
	for (int i = 1; i < n; i++) {
		Insert(1, 0, int(un.size()) - 1, a[i - 1]);
		int lef = lower_bound(un.begin(), un.end(), un[a[i]] - x) - un.begin() - 1;
		if (lef >= 0) Remove(1, 0, int(un.size()) - 1, 0, lef);
		int rig = upper_bound(un.begin(), un.end(), un[a[i]] + x) - un.begin();
		if (rig < un.size()) Remove(1, 0, int(un.size()) - 1, rig, int(un.size()) - 1);
		if (cnt[1] == 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &s1, &s2);
	un.push_back(s1); un.push_back(s2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); un.push_back(a[i]);
	}
	sort(un.begin(), un.end());
	s1 = getInd(s1), s2 = getInd(s2);
	for (int i = 0; i < n; i++)
		a[i] = getInd(a[i]);
	int lef = 0, rig = 1000000000;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Check(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%d\n", rig + 1);
	return 0;
}