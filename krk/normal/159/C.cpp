#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Maxl = 26;

int k;
string lin;
string s;
vector <int> I[Maxl];
int n;
vector <int> er[Maxl];
int st[Maxm];
bool del[Maxn];

void Create(int v, int l, int r)
{
	st[v] = r - l + 1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

int Get(int v, int l, int r, int x)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if (x <= st[2 * v]) return Get(2 * v, l, m, x);
		else return Get(2 * v + 1, m + 1, r, x - st[2 * v]);
	}
}

void Erase(int v, int l, int r, int x)
{
	st[v]--;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Erase(2 * v, l, m, x);
		else Erase(2 * v + 1, m + 1, r, x);
	}
}

int main()
{
	scanf("%d", &k); getline(cin, lin);
	getline(cin, lin);
	s.resize(k * lin.length());
	for (int i = 0; i < k; i++)
		for (int j = 0; j < lin.length(); j++) {
			int ind = i * lin.length() + j;
			s[ind] = lin[j]; I[lin[j] - 'a'].push_back(ind);
		}
	scanf("%d", &n);
	while (n--) {
		int p; char c; scanf("%d %c", &p, &c);
		er[c - 'a'].push_back(p);
	}
	for (int i = 0; i < Maxl; i++) {
		Create(1, 0, I[i].size() - 1);
		for (int j = 0; j < er[i].size(); j++) {
			int ind = Get(1, 0, I[i].size() - 1, er[i][j]);
			del[I[i][ind]] = true; Erase(1, 0, I[i].size() - 1, ind);
		}
	}
	for (int i = 0; i < s.length(); i++)
		if (!del[i]) printf("%c", s[i]);
	printf("\n");
	return 0;
}