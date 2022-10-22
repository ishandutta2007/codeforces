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
typedef long double ld;
typedef pair <ll, int> lli;

const int Maxn = 100005;

int n, m, r, k;
vector <ll> R, C;
int pnt[Maxn];
priority_queue <lli> Q;
ld res;

int main()
{
	scanf("%d %d %d %d", &n, &m, &r, &k);
	for (int i = 0; i < n; i++) {
		int lef = max(0, i - r + 1), rig = min(i, n - r);
		R.push_back(rig - lef + 1);
	}
	for (int i = 0; i < m; i++) {
		int lef = max(0, i - r + 1), rig = min(i, m - r);
		C.push_back(rig - lef + 1);
	}
	sort(R.begin(), R.end()); sort(C.begin(), C.end());
	for (int i = 0; i < R.size(); i++) {
		pnt[i] = int(C.size()) - 1;
		Q.push(lli(ll(R[i]) * C[pnt[i]], i));
	}
	ld dv = ll(n - r + 1) * (m - r + 1);
	while (k > 0) {
		ll cur = Q.top().first;
		int wh = Q.top().second; Q.pop();
		pnt[wh]--;
		if (pnt[wh] >= 0)
			Q.push(lli(ll(R[wh]) * C[pnt[wh]], wh));
		res += cur / dv;
		k--;
	}
	cout << fixed << setprecision(13) << res << endl;
	return 0;
}