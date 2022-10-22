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

bool solve() {
	
	char buffer[300300];
	scanf("%s", &buffer);

	int n = strlen(buffer);
	ll ans = 0;

	for(int i = 0;i < n;i++) {
		if((buffer[i] - '0') % 4 == 0) ans++;
		if(i > 0 && ((buffer[i - 1] - '0') * 10 + buffer[i] - '0') % 4 == 0) {
			ans += i;
		}
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}