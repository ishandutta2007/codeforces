#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 55;

int n, m;
int X[Maxn], Y[Maxn];
ii p[Maxn];
int val[Maxn][Maxn];
vector <iii> srt;
vector <ii> res1, res2;

void Move(ii &p, ii nxt)
{
	res1.push_back(p); res2.push_back(nxt);
	val[nxt.first][nxt.second] = val[p.first][p.second];
	val[p.first][p.second] = -1;
	p = nxt;
}

void moveToFirst(int ind, int col)
{
	while (p[ind].first > 2) Move(p[ind], ii(p[ind].first - 1, p[ind].second));
	while (p[ind].first == 2)
		if (p[ind].second >= col) Move(p[ind], ii(p[ind].first - 1, p[ind].second));
		else Move(p[ind], ii(p[ind].first, p[ind].second + 1));
	while (p[ind].second > col) Move(p[ind], ii(p[ind].first, p[ind].second - 1));
}

bool Better1(const ii &a, const ii &b)
{
	if (a.first != b.first) return a.first < b.first;
	if (a.first == 1) return a.second < b.second;
	return a.second > b.second;
}

bool BetterSolve(const iii &ga, const iii &gb)
{
	ii a = ga.first, b = gb.first;
	if (a.first != b.first) return a.first < b.first;
	if (a.first == 1) return a.second < b.second;
	return a.second > b.second;
}

void Solve(int ind, ii needed)
{
	while (p[ind].first + 1 < needed.first) Move(p[ind], ii(p[ind].first + 1, p[ind].second));
	while (p[ind].first + 1 == needed.first)
		if (p[ind].second >= needed.second) Move(p[ind], ii(p[ind].first + 1, p[ind].second));
		else Move(p[ind], ii(p[ind].first, p[ind].second + 1));
	while (p[ind].second > needed.second) Move(p[ind], ii(p[ind].first, p[ind].second - 1));
	while (p[ind].second < needed.second) Move(p[ind], ii(p[ind].first, p[ind].second + 1));
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n == 1) { printf("0\n"); return 0; }
	for (int i = 0; i < m; i++)
		scanf("%d %d", &X[i], &Y[i]);
	for (int i = 0; i < m; i++) {
		iii p; scanf("%d %d", &p.first.first, &p.first.second);
		p.second = i;
		srt.push_back(p);
	}
	sort(srt.begin(), srt.end(), BetterSolve);
	for (int i = 0; i < srt.size(); i++)
		p[i] = ii(X[srt[i].second], Y[srt[i].second]);
	fill((int*)val, (int*)val + Maxn * Maxn, -1);
	for (int i = 0; i < m; i++)
		val[p[i].first][p[i].second] = i;
	// to 1st row
	for (int j = 1; j <= m; j++) {
		ii best = ii(n + 1, -n - 1);
		int bi = -1;
		for (int k = 0; k < m; k++)
			if (p[k].first == 1 && p[k].second >= j || p[k].first > 1)
				if (Better1(p[k], best)) { best = p[k]; bi = k; }
		assert(bi != -1);
		moveToFirst(bi, j);
	}
	// to 2nd row
	for (int i = 0; i < m; i++)
		Move(p[i], ii(p[i].first + 1, p[i].second));
	// to 1st again
	for (int i = 0; i < m; i++) {
		int col = p[i].second;
		Move(p[i], ii(p[i].first - 1, p[i].second));
		while (p[i].second > i + 1) Move(p[i], ii(p[i].first, p[i].second - 1));
		for (int j = col; j > i + 1; j--) {
			int ind = val[2][j - 1];
			Move(p[ind], ii(p[ind].first, p[ind].second + 1));
		}
	}
	for (int i = m - 1; i >= 0; i--)
		Solve(i, srt[i].first);
	assert(res1.size() <= 10800);
	printf("%d\n", int(res1.size()));
	for (int i = 0; i < res1.size(); i++)
		printf("%d %d %d %d\n", res1[i].first, res1[i].second, res2[i].first, res2[i].second);
	return 0;
}