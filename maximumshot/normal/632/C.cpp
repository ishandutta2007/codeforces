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

const int N = 60;
char buffer[N];

bool cmp(const string & a, const string & b) {
	return (a + b < b + a);
}

bool solve() {
		
	int n;
	scanf("%d", &n);

	vec< string > a(n);

	for(int i = 0;i < n;i++) {
		scanf("%s", &buffer);
		a[i] = buffer;
	}

	sort(ALL(a), cmp);

	for(int i = 0;i < n;i++) cout << a[i];
	cout << '\n';

	return true;
}

int main() {

	//swhile(solve());
	solve();
	
	return 0;
}