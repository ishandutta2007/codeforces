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
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 0;
	
	for(int l = 0;l < n;l++) {
		int x = 0;
		int y = 0;
		for(int r = l;r < n;r++) {
			if(s[r] == 'L') x--;
			else if(s[r] == 'R') x++;
			else if(s[r] == 'U') y++;
			else y--;
			if(x == 0 && y == 0) ans++;
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