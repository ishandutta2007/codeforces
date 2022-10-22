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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int hoge[4] = {};
	REP(i, s.length()) {
		if (s[i] == 'A')hoge[0]++;
		else if (s[i] == 'G') hoge[1]++;
		else if (s[i] == 'T')hoge[2]++;
		else if(s[i] == 'C') hoge[3]++;
	}
	string ans;
	REP(i, s.length()) {
		if (s[i] == '?') {
			int minimum = 1000;
			int miw = -1;
			for (int q = 0;q < 4;++q) {
				if (minimum > hoge[q]) {
					minimum = hoge[q];
					miw = q;
				}
			}
			if (miw == 0) {
				ans.push_back('A');
			}
			else if (miw == 1) {
				ans.push_back('G');
			}
			else if (miw == 2) {
				ans.push_back('T');
			}else{
				ans.push_back('C');
			}
			hoge[miw]++;
		}
		else {
			ans.push_back(s[i]);
		}
	}
	if (hoge[0] == hoge[1]&&hoge[1] == hoge[2]&&hoge[2] == hoge[3]) {
		cout << ans << endl;
		return 0;
	}
	else cout << "===" << endl;
	return 0;
}