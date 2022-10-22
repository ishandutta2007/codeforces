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
int main(){
#define int long long
	int query;
	cin >> query;
	REP(tea, query) {
		long long n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int cnt_one = 0;
		int cnt_zero = 0;
		int ok = 0;
		REP(i, s.length()) {
			if (s[i] == '1') {
				cnt_one++;
			}
			else {
				if (cnt_one >= k) {
					//this scene is final
					ok = 1;
					int hoge = cnt_one - k;
					REP(i, cnt_zero) {
						cout << "0";
					}
					REP(i, hoge) {
						cout << "1";
					}
					cout << "0";
					REP(i, cnt_one - hoge) {
						cout << "1";
					}
					for (int j = i + 1; j < s.length(); ++j) {
						cout << s[j];
					}
					cout << endl;
					break;
				}
				cnt_zero++;
				k -= cnt_one;
			}
		}
		if (ok == 0) {
			REP(i, cnt_zero) {
				cout << "0";
			}
			REP(i, cnt_one) {
				cout << "1";
			}
			cout << endl;
		}
	}
}