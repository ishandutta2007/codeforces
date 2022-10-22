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

const int NMAX = 100100;
char buff[NMAX];

int n, k;
int s[NMAX];

int get(int l, int r) {
	return s[r] - (l?s[l - 1] : 0);
}

bool check(int l) {
	for(int x, i = 0;i + l - 1 < n;i++) {
		// [i .. i + l - 1]
		x = get(i, i + l - 1);
		if(min(x, l - x) <= k) return 1;
	}
	return 0;
}

bool solve() {
	
	scanf("%d %d %s", &n, &k, &buff);	

	for(int x = 0, i = 0;i < n;i++) {
		if(buff[i] == 'a') x++;
		s[i] = x;
 	}

	int bl, br, bm;
	bl = 1;
	br = n;

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(check(bm)) bl = bm;
		else br = bm - 1;
	}

	if(check(br)) printf("%d\n", br);
	else printf("%d\n", bl);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}