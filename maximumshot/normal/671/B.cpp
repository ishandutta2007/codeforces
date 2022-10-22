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
#include <unordered_map>
#include <array>

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

int n, k;
vec< int > c;
vec< ll > sum;

ll gets(int l, int r) {
	l = max(l, 0);
	r = min(r, n - 1);
	if(l > r) return 0;
	return sum[r] - (l?sum[l - 1] : 0);
}

int getc(int l, int r) {
	l = max(l, 0);
	r = min(r, n - 1);
	if(l > r) return 0;
	else return r - l + 1;
}

bool check(int cur) {
	int id = upper_bound(ALL(c), cur) - c.begin();
	// [0 .. id - 1]
	ll s1 = 1ll * getc(0, id - 1) * cur - gets(0, id - 1);
	ll s2 = gets(id, n - 1) - 1ll * getc(id, n - 1) * cur;
	return (s1 <= k && s1 <= s2);
}

bool check2(int cur) {
	int id = lower_bound(ALL(c), cur) - c.begin();
	ll s1 = 1ll * getc(0, id - 1) * cur - gets(0, id - 1);
	ll s2 = gets(id, n - 1) - 1ll * getc(id, n - 1) * cur;
	return (s2 <= k && s2 <= s1);
}

bool solve() {
	
	scanf("%d %d", &n, &k);

	c.resize(n);
	sum.resize(n);

	for(int i = 0;i < n;i++) {
		scanf("%d", &c[i]);
	}

	sort(ALL(c));

	for(int i = 0;i < n;i++) {
		sum[i] = c[i];
		if(i > 0) sum[i] += sum[i - 1];
	}

	int bl, br, bm;

	bl = *min_element(ALL(c));
	br = *max_element(ALL(c));

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(check(bm)) bl = bm;
		else br = bm - 1;
	}

	int L = (check(br)?br : bl);

	bl = L;
	br = *max_element(ALL(c));

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(check2(bm)) br = bm;
		else bl = bm + 1;
	}

	int R = (check2(bl)?bl : br);

	printf("%d\n", R - L);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}