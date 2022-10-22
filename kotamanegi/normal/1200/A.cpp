/*

This Submission is to determine how many 120/240 min const. delivery point there are.

*/
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
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int done[111];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	REP(i, s.length()) {
		if (s[i] == 'L') {
			REP(q, 10) {
				if (done[q] == 0) {
					done[q] = 1;
					break;
				}
			}
		}
		else if (s[i] == 'R') {
			REP(q, 10) {
				if (done[9 - q] == 0) {
					done[9 - q] = 1;
					break;
				}
			}
		}
		else {
			done[s[i] - '0'] = 0;
		}
	}
	REP(i, 10) {
		cout << done[i];
	}
	cout << endl;
}