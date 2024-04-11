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
	scanf("%d", &n);

	char buff[15];
	vec< string > s(n);
	vec< ll > h(n);

	for(int i = 0;i < n;i++) {
		scanf("%s", &buff);
		s[i] = buff;
		ll value = 0;
		for(int j = 0;j < (int)s[i].size();j++) {
			value = (value * 27ll + s[i][j] - 'a' + 1);
		}
		h[i] = value;
	}

	set< ll > q;

	for(int i = n - 1;i >= 0;i--) {
		if(!q.count(h[i])) {
			q.insert(h[i]);
			for(int j = 0;j < (int)s[i].size();j++) {
				printf("%c", s[i][j]);
			}
			printf("\n");
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}