#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef unsigned uint;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

int main() {
	#ifndef MY
	//freopen("czjanshdzy.in", "r", stdin);
	//freopen("czjanshdzy.out", "w", stdout);
	#endif
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	
	cout << "2000\n";
	for (int x = 1; x <= 1000; ++x) {
		cout << x << " 1 " << x << " 2\n";
	}
	//cout << "1000 1 1000 2\n";
	for (int x = 1000; x >= 1; --x) {
		cout << x << " 1 " << x << " 2\n";
	}
}