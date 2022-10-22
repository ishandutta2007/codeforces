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
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxm = 4;

int n, m;
ii seq[Maxm];
bool mark[Maxm];
vector <int> tosort;
int res;
map <int, int> M;
vector <int> my;

int getLCA(int a, int b)
{
	while (a != b)
		if (a > b) a /= 2;
		else b /= 2;
	return a;
}

bool canReach(int a, int b)
{
	while (a > b)
		a /= 2;
	return a == b;
}

void Insert(int a, int b)
{
	while (a != b)
		if (a > b) { M[a]++; a /= 2; }
		else { M[b]++; b /= 2; }
	M[a]++;
}

int getAll(int x)
{
	int add = 1, res = 0;
	while (x <= n) {
		res += add; 
		add *= 2; x = 2 * x + 1;
	}
	int lft = x - add + 1;
	res += max(0, n - lft + 1);
	return res;
}

bool checkEq(int x)
{
	for (int i = 0; i < my.size(); i++)
		if (my[i] == x) return true;
	return false;
}

int checkReach(int x)
{
	for (int i = 0; i < my.size(); i++)
		if (canReach(my[i], x)) return true;
	return false;
}

int Get(int x)
{
	if (x > n || checkEq(x)) return 0;
	if (checkReach(x)) 
		return 1 + Get(2 * x) + Get(2 * x + 1);
	else return getAll(x);
}

int Solve2(int x)
{
	int res = 0;
	int v = x;
	while (v && !checkEq(v)) {
		res = (res + Get(v)) % mod;
		my.push_back(v);
		v /= 2;
	}
	while (x > v) {
		my.pop_back();
		x /= 2;
	}
	return res;
}

int Get1(int x, int lst)
{
	if (x > n || checkEq(x) || x == lst) return 0;
	bool cr = checkReach(x) || canReach(lst, x);
	my.push_back(x);
	int res = 0;
	if (cr) res = (ll(Solve2(lst)) + ll(Get1(2 * x, lst)) + ll(Get1(2 * x + 1, lst))) % mod;
	else res = ll(getAll(x)) * Solve2(lst) % mod;
	my.pop_back();
	return res;
}

int Solve1(int x, int lst)
{
	int res = 0;
	while (x && !checkEq(x) && x != lst) {
		res = (res + Get1(x, lst)) % mod;
		my.push_back(x);
		x /= 2;
	}
	return res;
}

void Solve(int m)
{
	M.clear();
	int ind1 = tosort[0], ind2;
	M[seq[ind1].first]++;
	for (int i = 0; i + 1 < m; i++) {
		ind1 = tosort[i]; ind2 = tosort[i + 1];
		Insert(seq[ind1].second, seq[ind2].first);
	}
	ind2 = tosort[m - 1];
	M[seq[ind2].second]++;
	for (map <int, int>::iterator it = M.begin(); it != M.end(); it++) {
		if (it->second > 1) return;
	}
	ind1 = tosort[0];
	my.clear();
	for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
		if (it->first != seq[ind1].first && it->first != seq[ind2].second)
			my.push_back(it->first);
	res = (res + Solve1(seq[ind1].first, seq[ind2].second)) % mod;
}

void Gen(int lvl, int mx)
{
	if (lvl >= mx) { Solve(lvl); return; }
	for (int i = 0; i < m; i++) if (!mark[i]) {
		mark[i] = true; tosort.push_back(i);
		Gen(lvl + 1, mx);
		swap(seq[i].first, seq[i].second);
		Gen(lvl + 1, mx);
		swap(seq[i].first, seq[i].second);
		mark[i] = false; tosort.pop_back();
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &seq[i].first, &seq[i].second);
	res = ll(n) * n % mod;
	for (int i = 1; i <= m; i++)
		Gen(0, i);
	printf("%d\n", res);
	return 0;
}