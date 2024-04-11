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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int required[10000] = {};
int now_fill[10000] = {};
int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0;i < s.length();++i) {
		required[(char)s[i]] = true;
	}
	long long min_can = 10000000;
	long long back = 0;
	for (int i = 0;i < s.length();++i) {
		now_fill[(char)s[i]]++;
		for (int q = 0;q < 300;++q) {
			if (required[q] == true && now_fill[q] == 0) {
				goto dont;
			}
		}
		bool next_die = false;
		for (int q = back;q < s.length();++q) {
			if (now_fill[(char)s[q]] == 1) {
				if (next_die == false) {
					min_can = min(min_can, i - back+1);
					next_die = true;
				}
				else {
					goto dont;
				}
			}
			back++;
			now_fill[(char)s[q]]--;
		}
	dont:;
	}
	cout << min_can << endl;
	return 0;
}