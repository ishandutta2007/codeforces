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

bool solve() {

	int n;
	scanf("%d", &n);

	vec< int > a(n);
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);

	sort(ALL(a));

	vec< int > b(n);
	
	int j = 0;

	for(int i = 0;i < n;i += 2, j++) {
		b[i] = a[j];
	}

	for(int i = 1;i < n;i += 2, j++) {
		b[i] = a[j];
	}

	for(int i = 0;i < n;i++) printf("%d ", b[i]);
	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}