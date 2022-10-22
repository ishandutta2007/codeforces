#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
	
	int n, m;

	scanf("%d %d", &n, &m);
	
	vec< int > a(n + 1), ans(m + 1);
	vec< pair< int, int> > b(m + 1);
	 
	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}

	for(int i = 1;i <= m;i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}

	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());

	int i1 = 0, i2 = 1;

	while(i2 <= m) {
		while(i1 + 1 <= n && a[i1 + 1] <= b[i2].first) i1++;
		ans[b[i2++].second] = i1;
	}

	for(int i = 1;i <= m;i++) printf("%d ", ans[i]);

	puts("");

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}