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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n;
	cin >> n;

	vec< int > aa(n), bb(n), a, b;

	for(int i = 0;i < n;i++) scanf("%d", &aa[i]);
	for(int i = 0;i < n;i++) scanf("%d", &bb[i]);

	for(int i = 0;i < n;i++) {
		if(aa[i] != 0) a.push_back(aa[i]);
		if(bb[i] != 0) b.push_back(bb[i]);
	}

	int j = -1;

	n--;

	for(int i = 0;i < n;i++) {
		if(a[i] == b[0]) {
			j = i;
			break;
		}
	}

	for(int i = 0;i < n;i++) {
		if(b[i] != a[(i + j) % n]) {
			cout << "NO\n";
			return true;
		}
	}

	cout << "YES\n";

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}