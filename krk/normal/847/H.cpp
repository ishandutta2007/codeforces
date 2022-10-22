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

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 4000000000000000000ll;

int n;
int a[Maxn];
int L[Maxn], R[Maxn];
ll bestL[Maxn], bestR[Maxn];
ll res = Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		bestL[i] = bestL[i - 1];
		L[i] = max(a[i], L[i - 1] + 1);
		bestL[i] += L[i] - a[i];
	}
	for (int i = n; i > 0; i--) {
		bestR[i] = bestR[i + 1];
		R[i] = max(a[i], R[i + 1] + 1);
		bestR[i] += R[i] - a[i];
	}
	for (int i = 0; i <= n; i++) {
		ll cand = bestL[i] + bestR[i + 1];
		if (L[i] == R[i + 1]) cand++;
		res = min(res, cand);
	}
	cout << res << endl;
	return 0;
}