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
int ok[200000] = {};
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	for (int i = 'a';i <= 'z';++i) {
		string pre_ans;
		for (int q = 0;q < s.length();++q) {
			if ((int)s[q] == i) {
				pre_ans.push_back(s[q]);
				ok[q] = true;
			}
		}
		int cnt = 0;
		for (int j = 0;j < s.length();++j) {
			if (ok[j] == false) {
				cnt++;
			}
			else {
				if (cnt >= n) goto failed_system_test;
				cnt = 0;
			}
		}
		if (cnt >= n) goto failed_system_test;
		//answer complete!
		sort(ans.begin(), ans.end());
		cout << ans;
		for (int j = 0;j < s.length();++j) {
			if ((int)s[j] == i) {
				int winner = 1;
				for (int p = j - 1;p >= 0;--p) {
					if (ok[p] == false) winner++;
					else break;
				}
				for (int p = j + 1;p < s.length();++p) {
					if (ok[p] == false) winner++;
					else break;
				}
				if (winner >= n) {
					cout << (char)i;
				}
				else ok[j] = false;
			}
		}
		cout << endl;
		return 0;
	failed_system_test:;
		ans += pre_ans;
	}
}