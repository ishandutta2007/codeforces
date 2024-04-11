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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ll m;
int c[Maxn], w[Maxn];
ll cur;
bool tk[Maxn];
priority_queue <ii> Q;
ll res;

int main() 
{
	scanf("%d %I64d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		if (c[i] % 100 != 0) Q.push(ii(-w[i] * (100 - c[i] % 100), i));
		m -= c[i] % 100;
		tk[i] = true;
		if (m < 0) {
			m += 100;
			res += -Q.top().first; tk[Q.top().second] = false; Q.pop();
		}
	}
	printf("%I64d\n", res);
	for (int i = 0; i < n; i++)
		if (tk[i]) printf("%d %d\n", c[i] / 100, c[i] % 100);
		else printf("%d 0\n", c[i] / 100 + 1);
    return 0;
}