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
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
int cnt[5][3] = {};
int main(){
	int n;
	cin >> n;
	int ans = 0;
	REP(i, n) {
		string s;
		cin >> s;
		REP(q, s.length()) {
			if (s[q] != 'X') {
				if (s[q] == 'S') {
					cnt[q][0]++;
				}
				else if(s[q] == 'M'){
					cnt[q][1]++;
				}
				else {
					cnt[q][2]++;
				}
				break;
			}
		}
	}
	REP(i, n) {
		string s;
		cin >> s;
		REP(q, s.length()) {
			if (s[q] != 'X') {
				if (s[q] == 'S') {
					cnt[q][0]--;
				}
				else if(s[q] == 'M') {
					cnt[q][1]--;
				}
				else {
					cnt[q][2]--;
				}
				break;
			}
		}
	}
	REP(i, 5) {
		REP(q, 3) {
			ans += abs(cnt[i][q]);
		}
	}
	cout << ans / 2 << endl;
}