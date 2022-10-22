//J^!w

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
int main(){
	long long n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	s = "0" + s;
	int ok = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '.') {
			ok = 1;
		}
		else if (ok == 1) {
			if (s[i] >= '5') {
				int itr = i;
				while (t != 0 && ok == 1) {
					if (s[itr] >= '5') {
						while (s.size() != itr) {
							s.pop_back();
						}
						t--;
						for (int q = s.size() - 1; q >= 0; --q) {
							if (s[q] == '.') {
								ok = 0;
								continue;
							}
							if (s[q] == '9') {
								if (ok == 1) {
									while (s.size() != q) {
										s.pop_back();
									}
								}
								else if(ok == 0) {
									s[q] = '0';
								}
							}
							else {
								s[q]++;
								break;
							}
						}
					}
					else if (s[itr] == '.') ok = 0;
					itr--;
				}
			}
		}
	}
	if (s[0] == '0') {
		s.erase(s.begin());
	}
	if (s[s.size()-1] == '.') {
		s.pop_back();
	}
	cout << s << endl;
}