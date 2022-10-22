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
			
	int n;
	scanf("%d", &n);

	vec< int > a(n), b(n), p(n);

	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}

	for(int i = 0;i < n;i++) {
		scanf("%d", &b[i]);
		b[i]--;
		p[b[i]] = i;
	}

	for(int i = 0;i < n;i++) {
		a[i] = p[a[i]];
		b[i] = p[b[i]];
	}

	int ans = 0;
	vec< pii > way;

	for(int i = n - 1;i >= 0;i--) {
		int j = 0;
		while(a[j] != i) j++;
		// a[j] = i
		for(int k = j;k <= i;k++) {
			if(a[k] <= j) {
				swap(a[k], a[j]);
				ans += k - j;
				if(k > j) way.push_back(mp(k + 1, j + 1));
				j = k;
			}
		}
	}
	
	printf("%d\n%d\n", ans, (int)way.size());

	for(auto i : way) printf("%d %d\n", i.first, i.second);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}