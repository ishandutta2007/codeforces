#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define ran 200020
int n, cst[ran], cnt[ran], to[ran];
int q[ran], op, cl;
bool bad[ran];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &cst[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &to[i]);
		cnt[to[i]] ++;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q[op++] = i;
		}
	}
	while (cl < op) {
		int x = q[cl++], y = to[x];
		if (--cnt[y] == 0) {
			q[op++] = y;
		}
	}
	for (int i = 0; i < op; i++)bad[q[i]] = true;
	int res = 0;
	for (int i = 1; i <= n; i++)if (!bad[i]) {
		int cur = 11111;
		for (int x = i; !bad[x]; x = to[x]) {
			cur = min(cur, cst[x]);
			bad[x] = true;
		}
		res += cur;
	}
	printf("%d\n", res);
	return 0;
}