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

int f(char c) {
	if(c >= '0' && c <= '9') return c - '0';
	else if(c >= 'A' && c <= 'Z') return 10 + c - 'A';
	else if(c >= 'a' && c <= 'z') return 36 + c - 'a';
	else if(c == '-') return 62;
	else return 63;
}

const int mod = inf + 7;

int sum(int a, int b) {
	return (a + b) % mod;
}

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

bool solve() {

	int res = 1;

	vec< int > cn(64);

	for(int x = 0;x < 64;x++) for(int y = 0;y < 64;y++) cn[x & y]++;

	char c;

	while(scanf(" %c", &c) == 1) {
		res = mul(res, cn[f(c)]);
	}

	printf("%d\n", res);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}