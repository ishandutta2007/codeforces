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
#include <stack>
#include <math.h>
#include <complex>

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

bool solve() {

	int n, k;
	
	scanf("%d %d", &n, &k);

	vec< int > a(n);
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);

	if(k == 0) {
		int res = 0;
		for(int i = 0;i < n;i++) {
			if(a[i] == 0) continue;
			int j = i;
			while(j < n && a[j] == 1) j++; 
			j--;
			res = max(res, j - i + 1);
			i = j;
		}
		printf("%d\n", res);
		for(int i = 0;i < n;i++) printf("%d ", a[i]);
		printf("\n");
		return true;
	}

	int res = -1, L, R;

	for(int cur = 0, j = 0, i = 0;i < n;i++) {
		if(a[i] == 0) cur++;
		while(cur > k) {
			if(a[j] == 0) cur--;
			j++;
		}
		if(res < i - j + 1) {
			res = i - j + 1;
			L = j;
			R = i;
		}
	}

	for(int i = L;i <= R;i++) a[i] = 1;

	printf("%d\n", res);
	for(int i = 0;i < n;i++) printf("%d ", a[i]);
	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}