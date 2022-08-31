#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;

int n;
ll a1[MAXN];
ll a2[MAXN];
ll b1[MAXN];
ll b2[MAXN];
ll sum = 0;
vector<ll> vv;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld%lld%lld", a1 + i, b1 + i, a2 + i, b2 + i);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		if (b2[i] >= a1[i] && a2[i] >= b1[i])
			continue;
		if (b2[i] < a1[i]) {
			a1[i] -= b2[i];
			b1[i] += b2[i];
			a2[i] += b2[i];
			b2[i] = 0;
			sum += a1[i];
			b1[i] += a1[i];
			a1[i] = 0;
			if (b1[i] > a2[i]) {
				sum -= b1[i];
				vv.push_back(b1[i]);
				vv.push_back(a2[i]);
			}
		}
		else {
			b1[i] -= a2[i];
			a1[i] += a2[i];
			b2[i] += a2[i];
			a2[i] = 0;
			sum -= b1[i];
			a1[i] += b1[i];
			b1[i] = 0;
			if (a1[i] > b2[i]) {
				sum -= b2[i];
				vv.push_back(a1[i]);
				vv.push_back(b2[i]);
			}
		}
	}
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < (int)vv.size(); ++i) {
		if (i % 2 == 0)
			sum += vv[i];
	}
	cout << sum << "\n";

	return 0;
}