#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

const int MAX = 1000010;

const int MAXN = 51000;
const int SQ = 300;

int n, m;
int go[MAX];
int a[MAXN];
int gn[MAXN];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	int x = get<0>(a);
	int y = get<0>(b);
	x /= SQ;
	y /= SQ;
	if (x < y)
		return 1;
	if (x > y)
		return 0;
	return get<1>(a) < get<1>(b);
}

vector<tuple<int, int, int> > qq;

int ans[MAXN];


//trie


int nowmem = 0;

struct node {
	int go[2];
	int mn;
	int mx;
	node() {
		go[0] = go[1] = 0;
		mn = 1000010;
		mx = -1;
	}
};

node mem[MAXN * 22];

void clear() {
	nowmem = 1;
	mem[0] = node();
}

int newn() {
	mem[nowmem] = node();
	return nowmem++;
}

void add(int x) {
	int now = 0;
	int y = go[x - 1];
	for (int i = 19; i >= 0; --i) {
		mem[now].mn = min(mem[now].mn, x);
		int g = (y >> i) & 1;
		if (mem[now].go[g])
			now = mem[now].go[g];
		else
			now = mem[now].go[g] = newn();
	}
	mem[now].mn = min(mem[now].mn, x);
	now = 0;
	y = go[x];
	for (int i = 19; i >= 0; --i) {
		mem[now].mx = max(mem[now].mx, x);
		int g = (y >> i) & 1;
		if (mem[now].go[g])
			now = mem[now].go[g];
		else
			now = mem[now].go[g] = newn();
	}
	mem[now].mx = max(mem[now].mx, x);
}

int get(int x) {
	int aa = 0;
	int now = 0;
	int y = go[x];
	if (mem[now].mn <= x) {
		for (int i = 19; i >= 0; --i) {
			int g = (y >> i) & 1;
			g ^= 1;
			if (mem[now].go[g] && mem[mem[now].go[g]].mn <= x)
				now = mem[now].go[g], y |= (1 << i);
			else {
				y ^= (y & (1 << i));
				now = mem[now].go[g ^ 1];
			}
		}
		aa = max(aa, y);
	}
	now = 0;
	y = go[x - 1];
	if (mem[now].mx >= x) {
		for (int i = 19; i >= 0; --i) {
			int g = (y >> i) & 1;
			g ^= 1;
			if (mem[now].go[g] && mem[mem[now].go[g]].mx >= x)
				now = mem[now].go[g], y |= (1 << i);
			else {
				y ^= (y & (1 << i));
				now = mem[now].go[g ^ 1];
			}
		}
		aa = max(aa, y);
	}
	return aa;
}


int main() {
//	freopen("in2", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= 1000000; ++i)
		go[i] = go[i - 1] ^ i;

	for (int i = 0; i <= n; i += SQ) {
		clear();
		int nowans = 0;
		for (int j = i - 1; j >= 0 && j + SQ >= i; --j) {
			add(a[j]);
			nowans = max(nowans, get(a[j]));
			gn[j] = nowans;
		}
	}

	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		qq.push_back(make_tuple(l, r, i));
	}
	sort(qq.begin(), qq.end(), cmp);
	int lst = 0;
	int now = 0;
	int nowans = 0;

	for (int i = 0; i < (int)qq.size(); ++i) {
		int l = get<0>(qq[i]);
		int r = get<1>(qq[i]);
		int q = get<2>(qq[i]);
		int nx = SQ * (l / SQ + 1);
		if (nx != lst)
			clear(), lst = nx, now = lst, nowans = 0;
		if (r < nx) {
			clear();
			nowans = 0;
			now = nx;
			int aa = 0;
			for (int j = l; j < r; ++j)
				add(a[j]), aa = max(aa, get(a[j]));
			clear();
			ans[q] = aa;
		}
		else {
			int aa = gn[l];
			while (now < r)
				add(a[now]), nowans = max(nowans, get(a[now])), ++now;
			aa = max(nowans, aa);
			for (int j = l; j < nx; ++j)
				aa = max(aa, get(a[j]));
			ans[q] = aa;
		}
	}

	for (int i = 0; i < m; ++i)
		cout << ans[i] << "\n";

	return 0;
}