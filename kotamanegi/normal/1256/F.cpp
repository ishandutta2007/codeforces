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
	int query;
	cin >> query;
	REP(tea, query) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		if (n == 1) {
			if (a == b) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			continue;
		}
		int cnt[2][26] = {};
		REP(i, a.length()) {
			cnt[0][a[i] - 'a']++;
		}
		REP(i, b.length()) {
			cnt[1][b[i] - 'a']++;
		}
		int ok = 1;
		REP(i, 26) {
			if (cnt[0][i] != cnt[1][i]) ok = 0;
		}
		int bo = 0;
		REP(i, 26) {
			if (cnt[0][i] >= 2) {
				bo = 1;
			}
		}
		if (bo == 0) {
			for (int te = 0; te < 2; ++te) {
				for (int q = 0; q < a.length()-1; ++q) {
					int now_minnest = 1000;
					int now_itr = 0;
					for (int j = q; j < a.length(); ++j) {
						if (now_minnest > a[j]) {
							now_minnest = a[j];
							now_itr = j;
						}
					}
					while (now_itr != q) {
						swap(b[b.length() - 1], b[b.length() - 2]);
						swap(a[now_itr], a[now_itr - 1]);
						now_itr--;
					}
				}
				swap(a, b);
			}
			if (a != b) ok = 0;
		}
		if (ok == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}