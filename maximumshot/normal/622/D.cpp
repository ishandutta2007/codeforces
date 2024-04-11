#include <iostream>
#include <vector>
#include <algorithm>
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
	cin >> n;

	if(n % 2 == 0) {
		for(int i = 1;i < n;i += 2) printf("%d ", i);
		for(int i = n - 1;i >= 1;i -= 2) printf("%d ", i);
		for(int i = 2;i <= n;i += 2) printf("%d ", i);
		for(int i = n - 2;i >= 2;i -= 2) printf("%d ", i);
		printf("%d\n", n);
	}else {
		for(int i = 1;i <= n;i += 2) printf("%d ", i);
		for(int i = n - 2;i >= 1;i -= 2) printf("%d ", i);
		for(int i = 2;i < n;i += 2) printf("%d ", i);
		for(int i = n - 1;i >= 2;i -= 2) printf("%d ", i);
		printf("%d\n", n);
	}

	return true;	
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}