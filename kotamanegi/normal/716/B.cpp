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
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int hoge[100000] = {};
int main() {
	string s;
	cin >> s;
	int max_letter = 0;
	REP(i, s.length()) {
		hoge[i] = (int)s[i];
	}
	int counters[1000] = {};
	string ans;
	if (s.length() < 26) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0;i < 26;++i) {
		if (s[i] != '?') {
			counters[hoge[i]]++;
		}
	}
	for (int i = 26;i <= s.length();++i) {
		for (int i = 'A';i <= 'Z';++i) {
			if (counters[i] > 1) {
				goto failed;
			}
		}
		//success
		cout << ans;
		for (int j = i - 26;j < i;++j) {
			if (s[j] == '?') {
				for (int t = 'A';t <= 'Z';++t) {
					if (counters[t] == 0) {
						cout << (char)t;
						counters[t]++;
						goto ok;
					}
				}
			ok:;
			}
			else {
				cout << s[j];
			}
		}
		for (int j = i;j < s.length();++j) {
			if (s[j] == '?') {
				cout << 'A';
			}else{
				cout << s[j];
			}
		}
		return 0;
	failed:;
		if (i != s.length()) {
			if (s[i] == '?'){
			}
			else {
				counters[hoge[i]]++;
			}
			if (s[i - 26] == '?') {
			}
			else {
				counters[hoge[i - 26]]--;
			}
			if (s[i - 26] != '?') {
				ans.push_back(s[i - 26]);
			}
			else {
				ans.push_back('A');
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}