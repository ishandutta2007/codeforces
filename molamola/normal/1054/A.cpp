#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int main() {
	int x, y, z, t1, t2, t3;
	scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
	ll a = t1 * abs(x - y);
	ll b = t2 * (abs(x - y) + abs(x - z)) + 3 * t3;
	if(a >= b) puts("YES");
	else puts("NO");
	return 0;
}