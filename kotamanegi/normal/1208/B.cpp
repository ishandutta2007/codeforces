/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
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
map<int,int> done;
int main() {
	int n;
	cin >> n;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	int now_itr = n - 1;
	int ans = 1e5;
	while (now_itr != -1 && done[inputs[now_itr]] == 0) {
		done[inputs[now_itr]]++;
		now_itr--;
	}
	if (now_itr == -1) {
		cout << 0 << endl;
		return 0;
	}
	ans = min(ans, now_itr+1);
	for (int i = 0; i < n; ++i) {
		while (now_itr != n - 1 && done[inputs[i]] >= 1) {
			done[inputs[now_itr + 1]]--;
			now_itr++;
		}
		if (now_itr == n - 1 && done[inputs[i]] >= 1) {
			break;
		}
		done[inputs[i]]++;
		ans = min(ans, now_itr + 1 - (i + 1));
	}
	cout << ans << endl;
}