#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxt = 1000005;

int n, e;
int a[Maxn], b[Maxn];
int T;
int conf[Maxt];
vector <int> my[Maxn];
int team[Maxn];

int Random() { return rand() << 15 | rand(); }

int Random(int l, int r) { return Random() % (r - l + 1) + l; }

int main()
{
	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (int i = 1; i <= n; i++) {
		int siz; scanf("%d", &siz);
		my[i].resize(siz);
		for (int j = 0; j < my[i].size(); j++) {
			scanf("%d", &my[i][j]); T = max(T, my[i][j]);
		}
	}
	while (true) {
		for (int i = 1; i <= T; i++)
			conf[i] = Random(1, 2);
		for (int i = 1; i <= n; i++) {
			int a = -1, b = -1;
			for (int j = 0; j < my[i].size(); j++)
				if (conf[my[i][j]] == 1) a = my[i][j];
				else b = my[i][j];
			if (a == -1) team[i] = b;
			else if (b == -1) team[i] = a;
			else team[i] = Random(0, 1)? a: b;
		}
		int got = 0;
		for (int i = 0; i < e; i++)
			got += conf[team[a[i]]] != conf[team[b[i]]];
		if (got >= (e + 1) / 2) break;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", team[i], i + 1 <= n? ' ': '\n');
	for (int i = 1; i <= T; i++)
		printf("%d%c", conf[i], i + 1 <= T? ' ': '\n');
	return 0;
}