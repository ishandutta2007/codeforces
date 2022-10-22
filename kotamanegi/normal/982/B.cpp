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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int n;
	cin >> n;
	set<pair<int, int>> a;
	REP(i, n) {
		int t;
		cin >> t;
		a.insert(make_pair(t, i + 1));
	}
	set<pair<int, int>> b;
	string s;
	cin >> s;
	REP(i,n*2){
		if (s[i] == '0') {
			auto i = a.begin();
			cout << (*i).second << " ";
			b.insert(*i);
			a.erase(i);
		}
		else {
			auto i = b.end();
			i--;
			cout << (*i).second << " ";
			b.erase(i);
		}
	}
	cout << endl;
}