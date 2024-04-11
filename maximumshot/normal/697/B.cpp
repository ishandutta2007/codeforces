#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

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

void er(string & s) {
	string t = "";
	for(char c : s) if(c != '.') t.push_back(c);
	s = t;
}

bool solve() {
	
	string s, a = "";
	cin >> s;
	int b = 0;
	
	for(int ok = 0, i = 0;i < (int)s.size();i++) {
		if(s[i] == 'e') ok = 1;
		else {
			if(ok) b = b * 10 + s[i] - '0';
			else a.push_back(s[i]);
		}
	}

	int pt = a.find('.') - 1 + b;

	er(a);

	while((int)a.size() - 1 < pt) a.push_back('0');
	
	for(int i = 0;i <= pt;i++) cout << a[i];
	if(pt < (int)a.size() - 1 && a.back() != '0') {
		cout << '.';
		for(int i = pt + 1;i < (int)a.size();i++) cout << a[i];
	}

	cout << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}