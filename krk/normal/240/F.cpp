#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxm = 524288;
const int Maxl = 26;

int n, m;
string s;
int freq[Maxm][Maxl], st[Maxm];
int cur[Maxl];
int part[Maxl];

void Create(int v, int l, int r)
{
	if (l == r) freq[v][s[l] - 'a']++;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		for (int i = 0; i < Maxl; i++)
			freq[v][i] = freq[2 * v][i] + freq[2 * v + 1][i];
	}
}

void Divide(int freq[], int part1[], int part2[], int need, int flag)
{
	fill(part1, part1 + Maxl, 0); fill(part2, part2 + Maxl, 0);
	if (flag == 1)
		for (int i = 0; i < Maxl; i++) {
			int tk = min(need, freq[i]); need -= tk;
			part1[i] += tk; part2[i] += freq[i] - tk;
		}
	else for (int i = Maxl - 1; i >= 0; i--) {
			int tk = min(need, freq[i]); need -= tk;
			part1[i] += tk; part2[i] += freq[i] - tk;
		}
}

void Down(int v, int l, int r)
{
	int m = l + r >> 1;
	st[2 * v] = st[2 * v + 1] = st[v];
	Divide(freq[v], freq[2 * v], freq[2 * v + 1], m - l + 1, st[v]);
	st[v] = 0;
}

void Get(int v, int l, int r, int a, int b)
{
	if (l != r && st[v]) Down(v, l, r);
	if (l == a && r == b)
		for (int i = 0; i < Maxl; i++)
			cur[i] += freq[v][i];
	else {
		int m = l + r >> 1;
		if (a <= m) Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
	}
}

void Insert(int v, int l, int r, int a, int b, int cnt[], int s)
{
	if (l == a && r == b) {
		for (int i = 0; i < Maxl; i++) freq[v][i] = cnt[i];
		st[v] = s;
	} else {
		if (st[v]) Down(v, l, r);
		int m = l + r >> 1;
		if (b <= m) Insert(2 * v, l, m, a, b, cnt, s);
		else if (m + 1 <= a) Insert(2 * v + 1, m + 1, r, a, b, cnt, s);
		else {
			int part1[Maxl], part2[Maxl];
			Divide(cnt, part1, part2, m - a + 1, s);
			Insert(2 * v, l, m, a, m, part1, s); 
			Insert(2 * v + 1, m + 1, r, m + 1, b, part2, s);
		}
		for (int i = 0; i < Maxl; i++)
			freq[v][i] = freq[2 * v][i] + freq[2 * v + 1][i];
	}
}

void Traverse(int v, int l, int r)
{
	if (l == r) {
		for (int i = 0; i < Maxl; i++)
			if (freq[v][i]) s[l] = 'a' + i;
	} else {
		if (st[v]) Down(v, l, r);
		int m = l + r >> 1;
		Traverse(2 * v, l, m); Traverse(2 * v + 1, m + 1, r);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	cin >> s;
	Create(1, 0, n - 1);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r); l--; r--;
		fill(cur, cur + Maxl, 0);
		Get(1, 0, n - 1, l, r);
		int odd = 0;
		for (int i = 0; i < Maxl; i++)
			odd += cur[i] % 2;
		if (odd <= 1) {
			fill(part, part + Maxl, 0);
			int mid = -1;
			for (int i = 0; i < Maxl; i++) {
				part[i] = cur[i] / 2;
				if (cur[i] % 2) mid = i;
			}
			int len = (r - l + 1) / 2;
			if (len) { Insert(1, 0, n - 1, l, l + len - 1, part, 1); Insert(1, 0, n - 1, r - len + 1, r, part, 2); }
			if (mid != -1) {
				fill(part, part + Maxl, 0); part[mid]++;
				Insert(1, 0, n - 1, l + len, l + len, part, 1);
			}
		}
	}
	Traverse(1, 0, n - 1);
	printf("%s\n", s.c_str());
	return 0;
}