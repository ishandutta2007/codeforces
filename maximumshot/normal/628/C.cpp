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

char buffer[100100];

bool solve() {
	
	int n, k;
	scanf("%d %d", &n, &k);

	scanf("%s", &buffer);
	string s;
	s = buffer;

	for(int i = 0;i < n && k > 0;i++) {
		int d1, d2;
		d1 = s[i] - 'a';
		d2 = 'z' - s[i];
		if(d1 >= d2) {
			int t = min(k, d1);
			s[i] -= t;
			k -= t;
		}else {
			int t = min(k, d2);
			s[i] += t;
			k -= t;
		}
	}

	if(k > 0) cout << "-1\n";
	else cout << s << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}