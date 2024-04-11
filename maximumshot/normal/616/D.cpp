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

bool solve() {
	
	int n, k;

	scanf("%d %d", &n, &k);

	vec< int > a(n);
	vec< int > used(1000001);

	for(int i = 0;i < n;i++) scanf("%d", &a[i]);

	int L, R;
	L = -1;
	R = -2;

	for(int c = 0, l = 0, r = 0;r < n;r++) {
		if(used[a[r]] == 0) c++;
		used[a[r]]++;
		// [l .. r]
		while(c > k) {
			used[a[l]]--;
			if(used[a[l]] == 0) c--;
			l++;
		}
		if(R - L < r - l) {
			tie(L, R) = mt(l, r);
		}
	}

	cout << L + 1 << " " << R + 1 << '\n'; 

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}