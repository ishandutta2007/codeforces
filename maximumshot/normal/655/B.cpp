#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int n, k;

	scanf("%d %d", &n, &k);

	vec< int > p(n);
	for(int i = 0;i < n;i++) p[i] = i;

	for(int i = 0;i < n / 2 && k > 0;i++, k--) {
		swap(p[i], p[n - 1 - i]);
	}

	ll ans = 0;

	vec< int > c(n);

	for(int i = n - 1;i >= 0;i--) {
		for(int cur = p[i] - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) ans += c[cur];
		for(int cur = p[i];cur < n;cur = cur | (cur + 1)) c[cur]++;
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}