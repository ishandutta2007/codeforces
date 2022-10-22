#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxm = 1024;

int n, k, x;
int cur, cnt[2][Maxm];

int main() 
{
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[cur][a]++;
	}
	while (k--) {
		int was = 0;
		for (int j = 0; j < Maxm; j++)
			if (cnt[cur][j]) {
				int ch = (cnt[cur][j] + 1 - was) / 2;
				cnt[!cur][j ^ x] += ch;
				cnt[!cur][j] += cnt[cur][j] - ch;
				was = (was + cnt[cur][j]) % 2;
				cnt[cur][j] = 0;
			}
		cur = !cur;
	}
	int mn = 0;
	while (!cnt[cur][mn]) mn++;
	int mx = Maxm - 1;
	while (!cnt[cur][mx]) mx--;
	printf("%d %d\n", mx, mn);
    return 0;
}