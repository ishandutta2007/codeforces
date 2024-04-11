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
int main() {
	string s;
	cin >> s;
	int starting = 100000000;
	for (int i = 0;i < s.length();++i) {
		if (s[i] != 'a') {
			starting = i;
			goto ok;
		}
	}
ok:;
	string ans;
	if (starting != 100000000) {
		for (int i = 0;i < starting;++i) {
			ans.push_back(s[i]);
		}
		for (int i = starting;i < s.length();++i) {
			if (s[i] != 'a') {
				int tmp = (int)s[i];
				tmp--;
				ans.push_back((char)tmp);
			}
			else {
				for (int q = i;q < s.length();++q) {
					ans.push_back(s[q]);
				}
				goto solved;
			}
		}
	}
	else {
		for (int i = 0;i < s.length() - 1;++i) {
			ans.push_back(s[i]);
		}
		ans.push_back('z');
	}
solved:;
	cout << ans << endl;
	return 0;
}