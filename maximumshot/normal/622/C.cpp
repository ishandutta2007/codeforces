#include <iostream>
#include <vector>
#include <algorithm>
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

vec< int > a, r;
int n, m;

bool solve() {

	scanf("%d %d", &n, &m);

	a.resize(n + 1);
	r.resize(n + 1, n + 1);

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}

	for(int i = n - 1;i >= 1;i--) {
		if(a[i] != a[i + 1]) r[i] = i + 1;
		else r[i] = r[i + 1];
	}

	for(int ql, qr, x;m;m--) {
		scanf("%d %d %d", &ql, &qr, &x);
		if(a[ql] != x) printf("%d\n", ql);
		else {
			int p = r[ql];
			if(p <= qr) printf("%d\n", p);
			else puts("-1");
		}
	}

	return true;	
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}