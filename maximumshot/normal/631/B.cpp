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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);
	
bool solve() {
	
	int n, m, k;
	
	scanf("%d %d %d", &n, &m, &k);

    vec< int > a(n + 1), b(m + 1);
	vec< int > ta(n + 1, -1), tb(m + 1, -1);

	for(int ty, x, y, i = 0;i < k;i++) {
		scanf("%d %d %d", &ty, &x, &y);
		if(ty == 1) {
			a[x] = y;
			ta[x] = i;
		}else {
			b[x] = y;
			tb[x] = i; 
		}
	}

	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i] && b[j]) printf("%d ", (ta[i] > tb[j]?a[i] : b[j]));
			else if(a[i]) printf("%d ", a[i]);
			else if(b[j]) printf("%d ", b[j]);
			else printf("0 ");
		}
		printf("\n");
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}