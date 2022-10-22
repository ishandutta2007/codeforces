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

typedef long long ll;

const int Maxn = 100005;

int n;
int p[Maxn];
bool tk[Maxn];
vector <int> V;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		int cur = i;
		int cnt = 0;
		while (!tk[cur]) { cnt++; tk[cur] = true; cur = p[cur]; }
		V.push_back(cnt);
	}
	sort(V.begin(), V.end());
	if (V.size() >= 2) {
		int a = V.back(); V.pop_back();
		V.back() += a;
	}
	for (int i = 0; i < V.size(); i++)
		res += ll(V[i]) * V[i];
	printf("%I64d\n", res);
	return 0;
}