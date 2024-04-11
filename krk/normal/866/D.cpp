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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
int a[Maxn];
priority_queue <ii> Q;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--)
		if (Q.empty() || Q.top().first <= a[i]) Q.push(ii(a[i], 0));
		else {
			ii v = Q.top(); Q.pop();
			res += v.first - a[i];
			if (--v.second >= 0) Q.push(v);
			Q.push(ii(a[i], 1));
		}
	cout << res << endl;
	return 0;
}