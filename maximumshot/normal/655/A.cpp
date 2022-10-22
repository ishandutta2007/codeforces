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

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

void upd(string & s) {
	string ans = "";
	for(auto i : s) {
		if(i != 'X') ans += i;		
	}
	int pos = 0;
	for(int i = 0;i < 3;i++) {
		if(ans[i] == 'A') {
			pos = i;
			break;
		}
	}
	s = "";
	for(int i = pos;i < 3;i++) s += ans[i];
	for(int i = 0;i < pos;i++) s += ans[i];
}

bool solve() {

	string x, a, b;
	a = b = "";

	cin >> x;
	a += x;
	cin >> x;
	reverse(ALL(x));
	a += x;

	cin >> x;
	b += x;
	cin >> x;
	reverse(ALL(x));
	b += x;

	upd(a);
	upd(b);

	cout << (a == b?"YES" : "NO") << "\n";

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}