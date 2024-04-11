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

const int mod = 1000000007;
const int Maxn = 52;

struct pos {
	int ind, a[4];
	pos(int gind = 0, int ga1 = 0, int ga2 = 0, int ga3 = 0, int ga4 = 0) {
		ind = gind; a[0] = ga1; a[1] = ga2; a[2] = ga3; a[3] = ga4;
	}
	bool operator <(const pos &u) const {
		if (ind != u.ind) return ind < u.ind;
		for (int i = 0; i < 4; i++)
			if (a[i] != u.a[i]) return a[i] < u.a[i];
		return false;
	}
};

map <pos, int> M;
int n;
int a[Maxn];

void Add(const pos &p, int val)
{
	map <pos, int>::iterator it = M.find(p);
	if (it == M.end()) M[p] = val;
	else it->second = (it->second + val) % mod;
}

int C(int n, int k)
{
	int res = 1;
	for (int i = 0; i < k; i++)
		res *= n - i;
	for (int i = 2; i <= k; i++)
		res /= i;
	return res;
}

void Gen(int lvl, int lft, int wh, int add, pos &p)
{
	if (lvl >= 2 && lft >= a[wh]) return;
	if (lvl >= 4) {
		if (lft >= 1) p.a[1 + lft]++;
		Add(p, add);
		if (lft >= 1) p.a[1 + lft]--;
	} else {
		Gen(lvl + 1, lft, wh, add, p);
		int to;
		if (lvl < 2) to = lft >= a[wh]? 1: 0;
		else to = lft;
		for (int i = 1; i <= to && i <= p.a[lvl]; i++) {
			if (lvl % 2) p.a[lvl - 1] += i;
			int cur = C(p.a[lvl], i);
			p.a[lvl] -= i;
			Gen(lvl + 1, lft - i, wh, ll(cur) * add % mod, p);
			p.a[lvl] += i;
			if (lvl % 2) p.a[lvl - 1] -= i;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	a[0]--; a[1]--;
	int a0 = a[0] == 1;
	int a1 = a[0] == 2;
	int a2 = a[1] == 1;
	int a3 = a[1] == 2;
	M[pos(2, a0, a1, a2, a3)] = 1;
	for (map <pos, int>::iterator it = M.begin(); it != M.end(); )
		if (it->first.ind >= n) break;
		else {
			pos p = it->first;
			int add = it->second;
			if (p.a[0] == 0 && p.a[1] == 0) Add(pos(p.ind, p.a[2], p.a[3], 0, 0), add);
			else {
				pos u = p; u.ind++;
				Gen(0, a[p.ind], p.ind, add, u);
			}
			M.erase(it++);
		}
	int res = M[pos(n, 0, 0, 0, 0)];
	printf("%d\n", res);
	return 0;
}