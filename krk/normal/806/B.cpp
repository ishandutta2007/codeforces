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

const int Maxn = 122;
const int Maxm = 5;

int n;
int a[Maxn][Maxm];
int cnt[Maxm], tot[Maxm];

int getPoints(int pw) { return (pw + 1) * 500; }

int getCat(int a, int b)
{
	b = max(b, 1);
	for (int i = 5; i >= 0; i--)
		if (b >= ll(a) * (1ll << ll(i))) return i;
	return -1;
}

int getX(int a, int b, int cat)
{
	b = max(b, 1);
	return ll(a) * (1ll << ll(cat)) - b; 
}

bool Bet(int tima, int timb)
{
	if ((tima == -1) != (timb == -1)) return tima != -1;
	return tima < timb;
}

ll Get(int tim, int a, int b)
{
	if (tim == -1) return 0;
	int p = getPoints(getCat(a, b));
	return p - p / 250 * tim;
}

bool Solve(int x)
{
	ll my = 0ll, his = 0ll;
	for (int i = 0; i < Maxm; i++)
		if (Bet(a[0][i], a[1][i]) || a[0][i] == -1) {
			my += Get(a[0][i], cnt[i], tot[i] + x);
			his += Get(a[1][i], cnt[i], tot[i] + x);
		} else {
			my += Get(a[0][i], cnt[i] + x, tot[i] + x);
			his += Get(a[1][i], cnt[i] + x, tot[i] + x);
		}
	return my > his;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < Maxm; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] != -1) cnt[j]++;
		}
	for (int j = 0; j < Maxm; j++)
		tot[j] = n;
	vector <int> seq;
	seq.push_back(0); seq.push_back(1000000007);
	for (int j = 0; j < Maxm; j++) {
		int c = getCat(cnt[j], tot[j]);
		for (int i = c; i <= 4; i++) {
			int x = getX(cnt[j], tot[j], i + 1) - 1;
			if (x >= 0) seq.push_back(x);
		}
	}
	sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
	for (int i = 0; i < seq.size(); i++) if (Solve(seq[i])) {
		int lef = i == 0? 0: seq[i - 1] + 1;
		int rig = seq[i] - 1;
		while (lef <= rig) {
			int m = lef + rig >> 1;
			if (Solve(m)) rig = m - 1;
			else lef = m + 1;
		}
		printf("%d\n", rig + 1);
		return 0;
	}
	printf("-1\n");
	return 0;
}