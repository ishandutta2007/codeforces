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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
vector<long long> geko[26];
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	REP(i, 26) {
		geko[i].push_back(0);
	}
	for (int i = 0; i < s.length(); ++i) {
		geko[s[i] - 'a'].push_back(i + 1);
	}
	int query;
	cin >> query;
	REP(i, query) {
		string s;
		cin >> s;
		int cnt[26] = {};
		REP(i, s.length()) {
			cnt[s[i] - 'a']++;
		}
		long long neko = 0;
		REP(q, 26) {
			neko = max(neko, geko[q][cnt[q]]);
		}
		cout << neko << endl;
	}
}