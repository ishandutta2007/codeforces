#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int param[3000] = {};
int diff[3000] = {};
int appear[3000] = {};
int main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		param[i] = tmp;
		diff[i] = tmp;
		if (tmp <= m) {
			appear[tmp]++;
		}
	}
	int ans_dif = 0;
	int calc = n / m;
	for (int i = 0;i < n;++i) {
		if (param[i] > m) {
			for (int j = 1;j <= m;++j) {
				if (appear[j] < calc) {
					param[i] = j;
					appear[j]++;
					ans_dif++;
					goto ok;
				}
			}
		ok:;
		}
	}
	for (int i = 0;i < n;++i) {
		if (param[i] <= m&&appear[param[i]] > calc + 1) {
			for (int j = 1;j <= m;++j) {
				if (appear[j] < calc) {
					appear[param[i]]--;
					param[i] = j;
					appear[j]++;
					ans_dif++;
					goto ok2;
				}
			}
		ok2:;
		}
	}
	for (int i = 0;i < n;++i) {
		if (param[i] <= m&&appear[param[i]] > calc) {
			for (int j = 1;j <= m;++j) {
				if (appear[j] < calc) {
					appear[j]++;
					appear[param[i]]--;
					param[i] = j;
					ans_dif++;
					goto ok3;
				}
			}
		ok3:;
		}
	}
	for (int i = 0;i < n;++i) {
		if (param[i] > m) {
			for (int j = 1;j <= m;++j) {
				if (appear[j] < calc) {
					appear[j]++;
					param[i] = j;
					ans_dif++;
					goto ok4;
				}
			}
		ok4:;
		}
	}
	cout << calc << " " << ans_dif << endl;
	REP(i, n) {
		cout << param[i] << " ";
	}
	return 0;
}