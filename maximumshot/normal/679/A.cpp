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

bool solve() {
	
	int a[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

	int cnt = 0;

	string s;

	int y = -1;

	for(int i = 0;i < 15;i++) {
		printf("%d\n", a[i]);
		fflush(stdout);
		cin >> s;
		if(s == "yes") cnt++, y = a[i];
		if(cnt > 1) {
			printf("composite\n");
			fflush(stdout);
			return true;
		}
	}

	if(y == -1 || y * y > 100) { printf("prime\n"); fflush(stdout); }
	else {
		printf("%d\n", y * y);
		fflush(stdout);
		cin >> s;
		if(s == "yes") printf("composite\n");
		else printf("prime\n");
		fflush(stdout);
	}

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}