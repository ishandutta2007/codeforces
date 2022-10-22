#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool check(string s) {
	for(auto i : s) {
		if(i < '0' || i > '9') return 0;
	}
	if((int)s.size() > 1 && s[0] == '0' || (int)s.size() == 0) return 0;
	else return 1;
}

bool solve() {
	
	string s;

	cin >> s;

	s += ";";

	int n = (int)s.size();

	string a, b;
	a = b = "";

	int last = -1;
	int ok1 = 0, ok2 = 0;

	for(int i = 0;i < n;i++) {
		if(s[i] == ';' || s[i] == ',') {
			string x = "";
			for(int j = last + 1;j < i;j++) x += s[j];
			last = i;
			if(check(x)) a += x + ",", ok1 = 1;
			else b += x + ",", ok2 = 1;
		} 
	}

	if(!a.empty()) a.pop_back();
	if(!b.empty()) b.pop_back();

	if(ok1) cout << "\"" << a << "\"" << '\n';
	else cout << "-\n";
	if(ok2) cout << "\"" << b << "\"" << '\n';
	else cout << "-\n";

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}