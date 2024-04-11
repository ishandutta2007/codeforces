#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int t;
int n;
int L[Maxn], R[Maxn];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &L[i], &R[i]);
		int cur = 0;
		for (int i = 0; i < n; i++) {
			cur = max(cur, L[i]);
			if (cur > R[i]) {
				printf("0%c", i + 1 < n? ' ': '\n'); continue;
			} else {
				printf("%d%c", cur, i + 1 < n? ' ': '\n');
				cur++;
			}
		}
	}
	return 0;
}