#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int jiro[2][Maxn], len[2], ceil[Maxn];
bool taken[Maxn];

int Max1() // without destroying defence
{
	int res = 0;
	for (int i = 0; i < len[0]; i++) {
		int j = i, cand = 0;
		for (int k = m - 1; k >= 0 && j >= 0 && ceil[k] >= jiro[0][j]; k--, j--)
			cand += ceil[k] - jiro[0][j];
		res = max(res, cand);
	}
	return res;
}

int Max2() // destroying defence
{
	int res = 0;
	for (int i = 0; i < len[1]; i++) {
		int j = 0;
		while (j < m && (taken[j] || ceil[j] <= jiro[1][i])) j++;
		if (j == m) return 0;
		taken[j] = true;
	}
	for (int i = 0; i < len[0]; i++) {
		int j = 0;
		while (j < m && (taken[j] || ceil[j] < jiro[0][i])) j++;
		if (j == m) return 0;
		res += ceil[j] - jiro[0][i];
		taken[j] = true;
	}
	for (int i = 0; i < m; i++)
		if (!taken[i]) res += ceil[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		string pos;
		int stren;
		cin >> pos >> stren;
		if (pos == "ATK") jiro[0][len[0]++] = stren;
		else jiro[1][len[1]++] = stren;
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &ceil[i]);
	sort(jiro[0], jiro[0] + len[0]); sort(jiro[1], jiro[1] + len[1]);
	sort(ceil, ceil + m);
	printf("%d\n", max(Max1(), Max2()));
	return 0;
}