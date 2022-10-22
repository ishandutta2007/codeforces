#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <iomanip>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	long long ans = 0;
	REP(i, n) {
		string s;
		cin >> s;
		if (s == "Tetrahedron") {
			ans += 4;
		}
		if (s == "Cube") {
			ans += 6;
		}
		if (s == "Octahedron") {
			ans += 8;
		}
		if (s == "Dodecahedron") {
			ans += 12;
		}
		if (s == "Icosahedron") {
			ans += 20;
		}
	}
	cout << ans << endl;
	return 0;
}