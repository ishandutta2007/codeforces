#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

ull my_pow(ull n, int p) {
	ull ans = 1;
	for(int i = 0;i < p;i++) 
		ans *= n;
	return ans;
}

ull get() {
	ull value, n, osn;
	value = 0;
	cin >> n >> osn;
	for(int i = 0;i < n;i++) {
		ull x;
		cin >> x;
		value += x * my_pow(osn, n - i - 1);
	}
	return value;
}

bool solve()
{
	ull a, b;

	a = get();
	b = get();

	puts(a == b?"=" : (a < b?"<" : ">"));

	return true;
} 

int main() {

	//while(solve());
	solve();	

	return 0;
}