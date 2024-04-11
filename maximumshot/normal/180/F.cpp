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
#include <complex>

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

bool solve() {
	
	int n;

	scanf("%d", &n);
	
	vec< int > ta, tb, a, b;

	a = b = ta = tb = vec< int >(n + 1, 0);

	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), ta[a[i]] = i;
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]), tb[b[i]] = i;

	for(int i = 1;i <= n;i++) {
		int B, P;
		B = b[i];
		P = ta[B];
		printf("%d ", P);
	}

	puts("");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}