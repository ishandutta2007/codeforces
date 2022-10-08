#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int choice[14];

int no[50][50];

int goodChoice[14];

bool edge[14][14];

int got[7][7];

void color(int a, int c, int d) {
	if (d != -1)
		choice[a] = c;
	for (int i = 0; i < 14; ++i)
		if (edge[a][i] && choice[i] != -1) {
			got[c][choice[i]] += d;
		}
	if (d == -1)
		choice[a] = -1;
}

bool ok(int c) {
	for (int j = 0; j <= c; ++j)
		if (got[c][j] > 1)
			return false;
	return true;
}

int result;

void go(int c) {
	if (c == 7) {
		++result;
		for (int i = 0; i < 14; ++i)
			goodChoice[i] = choice[i];
	} else {
		for (int i = 0; i < 14; ++i) {
			if (choice[i] == -1) {
				color(i, c, 1);
				if (ok(c))
					for (int j = i + 1; j < 14; ++j) {
						if (choice[j] == -1) {
							color(j, c, 1);
							bool bad = false;
							for (int k = 0; k <= c; ++k)
								if (got[c][k] != 1) {
									bad = true;
								}
							if (!bad)
								go(c + 1);
							color(j, c, -1);
						}
					}
				color(i, c, -1);
			}
		}
	}
}

int height, width;

int n;

char t[50][50];

int main() {
	scanf("%d %d", &height, &width);
	for (int i = 0; i < height; ++i)
		scanf("%s", t[i]);
	memset(no, -1, sizeof(no));
	int edges = 0;
	for (int i = 0; i + 1 < height; ++i) {
		for (int j = 0; j + 1 < width; ++j) {
			if (no[i][j] == -1 && t[i][j] != '.') {
				no[i][j] = no[i + 1][j] = no[i][j + 1] = no[i + 1][j + 1] = n;
				++n;
			}
		}
	}
	int last = -1;
	for (int i = 0; i + 1 < height; ++i) {
		for (int j = 0; j + 1 < width; ++j) {
			if (no[i][j] == last + 1) {
				++last;
				if (t[i][j] == t[i][j + 1] || t[i][j] == t[i + 1][j]
						|| t[i + 1][j] == t[i + 1][j + 1] || t[i][j + 1] == t[i
						+ 1][j + 1])
					edge[last][last] = true;
				if (j >= 0 && t[i][j] == t[i][j - 1] && no[i][j - 1] != -1)
					edge[last][no[i][j - 1]] = true;
				if (j >= 0 && t[i + 1][j] == t[i + 1][j - 1] && no[i + 1][j - 1] != -1)
					edge[last][no[i + 1][j - 1]] = true;
				if (i >= 0 && t[i][j] == t[i - 1][j] && no[i - 1][j] != -1)
					edge[last][no[i - 1][j]] = true;
				if (i >= 0 && t[i][j + 1] == t[i - 1][j + 1] && no[i - 1][j + 1] != -1)
					edge[last][no[i - 1][j + 1]] = true;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			edge[i][j] |= edge[j][i];
			if (i <= j)
				edges += edge[i][j];
		}
	assert(n == 14);
	assert(edges == 28);
	memset(choice, -1, sizeof(choice));
	go(0);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (no[i][j] != -1)
				t[i][j] = goodChoice[no[i][j]] + '0';
		}
	}
	printf("%d\n", result);
	for (int i = 0; i < height; ++i)
		puts(t[i]);
}