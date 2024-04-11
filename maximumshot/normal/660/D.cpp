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

int gcd(int x, int y) {
	return (x == 0?y : gcd(y % x, x));
}

bool solve() {

	int n;
	
	scanf("%d", &n);

	vec< int > x(n), y(n);

	for(int i = 0;i < n;i++) scanf("%d %d", &x[i], &y[i]);

	vec< pii > a;

	for(int i = 0;i < n;i++) {
		int X, Y, G;
		for(int j = i + 1;j < n;j++) {
			X = x[j] - x[i];
			Y = y[j] - y[i];
			if(X < 0) X *= -1, Y *= -1;
			if(X == 0 && Y < 0) Y *= -1;
			a.push_back(mp(X, Y));
		}
	}

	sort(ALL(a));

	ll res = 0;

	for(int i = 0;i < (int)a.size();i++) {
		int j = i;
		while(j < (int)a.size() && a[i] == a[j]) j++; 
		j--;
		ll c = j - i + 1;
		res += c * (c - 1) / 2;
		i = j;
	}

	printf("%I64d\n", res / 2);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}