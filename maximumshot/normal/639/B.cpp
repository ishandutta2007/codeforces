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
#include <list>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, d, h;

bool solve() {
		
	cin >> n >> d >> h;

	if(h > d) {
		printf("-1\n");
		return true;
	}

	if(h + h < d) {
		printf("-1\n");
		return true;
	}

	if(h == 1 && d == 1 && n > 2) {
		printf("-1\n");
		return true;
	}

	if(1 + h > n || 1 + d > n) {
		printf("-1\n");
		return true;
	}

	for(int i = 2;i <= 1 + h;i++) {
		printf("%d %d\n", i - 1, i);
	}

	for(int i = 2 + h;i <= 1 + d;i++) {
		printf("%d %d\n", (i == 2 + h?1 : i - 1), i);
	}

	if(h < d) {
		for(int i = 1 + d + 1;i <= n;i++) { 
			printf("1 %d\n", i);
		}
	}else { // h == d
		for(int i = 1 + d + 1;i <= n;i++) {
			printf("2 %d\n", i);
		}
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}