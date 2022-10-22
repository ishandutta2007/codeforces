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
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

int n, k;
int c[Maxn];
priority_queue <ii> Q;
ll res;
int seq[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]); Q.push(ii(-c[i], i));
	}
	for (int i = k + n; i > k; i--)
		if (i <= n && !seq[i]) seq[i] = i;
		else {
			while (seq[Q.top().second]) Q.pop();
			ii v = Q.top(); Q.pop();
			res += ll(-v.first) * (i - v.second);
			seq[v.second] = i;
		}
	printf("%I64d\n", res);
	for (int i = 1; i <= n; i++)
		printf("%d%c", seq[i], i + 1 <= n? ' ': '\n');
	return 0;
}