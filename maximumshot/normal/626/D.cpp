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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

const int MAXS = 5050;

bool solve() {
	
	int n;
	scanf("%d", &n);

	vec< int > a(n);
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);
	sort(ALL(a));

	ll all = 1ll * n * (n - 1) / 2;

	all = all * all * all;

	vec< int > c1(MAXS), c2(MAXS);
	vec< ll > c3(MAXS * 2);

	for(int i = 0;i < n;i++) c1[a[i]]++;

	for(int i = 0;i < n;i++) {
		for(int j = i + 1;j < n;j++) {
			c2[a[j] - a[i]]++;
		}
	}

	for(int i = 0;i < MAXS;i++) {
		for(int j = 0;j < MAXS;j++) {
			c3[i + j] += 1ll * c2[i] * c2[j];
		}
	}

	for(int i = 1;i < MAXS * 2;i++) {
		c3[i] += c3[i - 1];
	}

	ll good = 0;

	for(int i = 1;i < MAXS;i++) {
		good += 1ll * c2[i] * c3[i - 1];
	}

	ld ans = (ld)good / (ld)all;

	cout.precision(10);
	cout << fixed << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}