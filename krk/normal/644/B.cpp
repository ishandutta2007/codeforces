#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, b;
int t[Maxn], d[Maxn];
queue <int> Q;
ll cur;
ll res[Maxn];

int main()
{
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &d[i]);
		while (cur <= t[i] && !Q.empty()) {
			int nxt = Q.front(); Q.pop();
			cur += d[nxt]; res[nxt] = cur;
		}
		if (cur <= t[i]) { cur = t[i] + d[i]; res[i] = cur; }
		else if (Q.size() < b) Q.push(i);
		else res[i] = -1;
	}
	while (!Q.empty()) {
		int nxt = Q.front(); Q.pop();
		cur += d[nxt]; res[nxt] = cur;
	}
	for (int i = 0; i < n; i++)
		printf("%I64d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}