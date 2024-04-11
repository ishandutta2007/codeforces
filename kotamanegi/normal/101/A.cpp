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
int ok[26] = {};
int cnt[26] = {};
int main(){
	string s;
	cin >> s;
	int k;
	cin >> k;
	REP(i, s.length()) {
		cnt[s[i] - 'a']++;
	}
	vector<pair<int, int>> go;
	REP(i, 26) {
		go.push_back(make_pair(cnt[i], i));
	}
	sort(go.begin(), go.end());
	int cnt = 26;
	REP(i, 26) {
		k -= go[i].first;
		if (k < 0) break;
		ok[go[i].second] = 1;
		cnt--;
	}
	cout << cnt << endl;
	REP(i, s.length()) {
		if (ok[s[i] - 'a'] == 0) {
			cout << s[i];
		}
	}
	cout << endl;
}