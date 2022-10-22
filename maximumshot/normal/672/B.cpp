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

int main() {
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	if(n > 26) {
	    cout << -1 << '\n';
	}else {
	    sort(ALL(s));
	    s.resize(unique(ALL(s)) - s.begin());
	    int sz = (int)s.size();
	    cout << n - sz << '\n';
	}
	
	return 0;
}