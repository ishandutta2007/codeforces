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

	int ans = 0;
	ll a, b;

	cin >> a >> b;

	for(int cnt_bit = 1;cnt_bit <= 63;cnt_bit++) {
		ll value = 0;
		for(int j = 0;j < cnt_bit;j++) value |= (1ll << j);
		for(int id_bit = 0;id_bit + 1 < cnt_bit;id_bit++) {
			ll tmp = value ^ (1ll << id_bit);
			if(a <= tmp && tmp <= b) ans++;
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