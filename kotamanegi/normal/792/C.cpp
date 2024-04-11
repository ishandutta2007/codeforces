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
#include<map>
#include <iomanip>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	string s;
	cin >> s;
	int tmp = 0;
	for (int i = 0;i < s.length();++i) {
		tmp += s[i] - '0';
		tmp %= 3;
	}
	string ans;
	if (tmp == 0) {
		cout << s << endl;
		return 0;
	}
	else {
		for (int i = s.length() - 1;i >= 0;--i) {
			if ((s[i] - '0') % 3 == tmp) {
				if (i == 0) {
					for (int q = 1;q <= s.length();++q) {
						if (s[q] != '0') {
							ans = s.substr(q);
							goto ok;
						}
					}
					goto ok;
				}
				else {
					ans = s;
					ans.erase(ans.begin() + i);
					goto ok;
				}
			}
		}
	ok:;
		tmp++;
		if (tmp == 3) tmp = 1;
		string pre_ans = s;
		for (int i = s.length() - 1;i >= 0;--i) {
			if ((s[i] - '0') % 3 == tmp) {
				pre_ans.erase(pre_ans.begin() + i);
				if (pre_ans.length() == s.length() - 2) {
					while (pre_ans.length() != 0 && pre_ans[0] == '0') {
						pre_ans.erase(pre_ans.begin());
					}
					if (ans.length() < pre_ans.length()) ans = pre_ans;
					goto fas;
				}
			}
		}
	fas:;
		if (ans == "") {
			for (int q = 0;q < s.length();++q) {
				if (s[q] == '0') {
					cout << 0 << endl;
					return 0;
				}
			}
			cout << -1 << endl;
			return 0;
		}else{
			cout << ans << endl;
			return 0;
		}
	}

}