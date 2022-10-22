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
int appeared[26] = {};
int union_tree[26] = {};
int union_find(int now) {
	if (union_tree[now] == now) return now;
	return union_tree[now] = union_find(union_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_tree[a] = b;
	return 0;
}
int main() {
	int n;
	cin >> n;
	REP(i, 26) {
		union_tree[i] = i;
	}
	REP(i, n) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		REP(q, s.length()) {
			if (q > 0) {
				union_merge(s[q - 1] - 'a', s[q] - 'a');
			}
			appeared[s[q] - 'a'] = 1;
		}
	}
	set<int> gogo;
	for (int i = 0; i < 26; ++i) {
		if (appeared[i] == 1) {
			gogo.insert(union_find(i));
		}
	}
	cout << gogo.size() << endl;
}