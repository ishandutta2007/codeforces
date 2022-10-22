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

const int Maxn = 15;
const int Maxm = 105;
const int Inf = 1000000000;

int n, m;
char B[Maxn][Maxm];
int res = Inf;

bool Check(const string &s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '1') return true;
	return false;
}

int Get(int mask)
{
	int res = n - 1, cur = 0, pos = 0;
	while (cur < n) {
		int nxt;
		if (pos == 0) {
			nxt = 0;
			for (int j = 0; j <= m + 1; j++)
				if (B[cur][j] == '1') nxt = j;
			res += nxt;
		} else {
			nxt = m + 1;
			for (int j = m + 1; j >= 0; j--)
				if (B[cur][j] == '1') nxt = j;
			res += m + 1 - nxt;
		}
		if (cur == n - 1) return res;
		if (mask & 1 << cur) res += m + 1 - nxt;
		else res += nxt;
		pos = bool(mask & 1 << cur); cur++; 
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = n - 1; i >= 0; i--)
		scanf("%s", B[i]);
	while (n > 0 && !Check(B[n - 1])) n--;
	if (n == 0) { printf("0\n"); return 0; }
	for (int i = 0; i < 1 << n - 1; i++) {
		res = min(res, Get(i));
	}
	printf("%d\n", res);
	return 0;
}