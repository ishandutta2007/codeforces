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

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, k, sz;
vec< int > a, pr, sf;

bool check(int mx_dist) {

	for(int j = 0, i = 0;i < sz;i++) {
		while(a[i] - a[j] > mx_dist) j++;
		pr[i] = j;
	}

	for(int j = sz - 1, i = sz - 1;i >= 0;i--) {
		while(a[j] - a[i] > mx_dist) j--;
		sf[i] = j;
	}

	for(int cnt, i = 0;i < sz;i++) {
		cnt = i - pr[i] + 1 + sf[i] - i;
		if(cnt >= k + 1) return 1;
	}

	return 0;
}

bool solve() {
	
	scanf("%d %d", &n, &k);

	for(int i = 0;i < n;i++) {
		char c;
		scanf(" %c", &c);
		if(c == '0') a.push_back(i);
	}

	sz = (int)a.size();
	pr.resize(sz);
	sf.resize(sz);

	int bl, br, bm;

	bl = 0;
	br = n;

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(check(bm)) br = bm;
		else bl = bm + 1;
	}

	if(check(bl)) printf("%d\n", bl);
	else printf("%d\n", br);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}