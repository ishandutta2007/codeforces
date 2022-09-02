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

int n, m;
char X[130][130];

int main() {
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", X[i]);
	int sum[2] = {}, cnt[2] = {};
	rep(i, n) rep(j, m) if(X[i][j] == 'B') {
		sum[0] += i; sum[1] += j;
		cnt[0]++;
	}
	printf("%d %d\n", sum[0] / cnt[0] + 1, sum[1] / cnt[0] + 1);
	return 0;
}