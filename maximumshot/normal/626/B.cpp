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

int f(char x) {
	if(x == 'B') return 0;
	else if(x == 'G') return 1;
	else return 2;
}

bool solve() {
	
	int n;
	cin >> n;

	vec< int > c(3);

	for(int i = 0;i < n;i++) {
		char x;
		cin >> x;
		c[f(x)]++;
	}

	if(c[0] > 0 && c[1] == 0 && c[2] == 0) {
		cout << "B\n";
	}else if(c[0] == 0 && c[1] > 0 && c[2] == 0) {
		cout << "G\n";
	}else if(c[0] == 0 && c[1] == 0 && c[2] > 0) {
		cout << "R\n";
	}else {

		if(c[1] > 0 && c[2] > 0) cout << "B";
		else if(max(c[1], c[2]) > 1) cout << "B";
		
		if(c[0] > 0 && c[2] > 0) cout << "G";
		else if(max(c[0], c[2]) > 1) cout << "G";

		if(c[0] > 0 && c[1] > 0) cout << "R";
		else if(max(c[0], c[1]) > 1) cout << "R";
	}


	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}