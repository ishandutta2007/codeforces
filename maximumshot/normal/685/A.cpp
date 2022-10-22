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
#include <complex>

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

vec< int > get(int x, int n) {
	vec< int > res;
	while(x) res.push_back(x % 7), x /= 7;
	while((int)res.size() < n) res.push_back(0);
	reverse(ALL(res));
	return res;
}

bool solve() {
	
	int n, m;

	cin >> n >> m;

	int c1 = 1, c2 = 1, val;
	
	val = 7;
	while(val < n) val *= 7, c1++;
	
	val = 7;
	while(val < m) val *= 7, c2++;
	
	if(c1 + c2 > 7) {
		cout << 0 << '\n';
		return true;
	}

	vec< int > a, b;
	set< int > q;

	int res = 0;

	for(int x = 0;x < n;x++) {
		for(int y = 0;y < m;y++) {
			a = get(x, c1);
			b = get(y, c2);
			q.clear();
			for(auto t : a) q.insert(t);
			for(auto t : b) q.insert(t);
			if((int)q.size() == c1 + c2) res++;
		}
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}