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
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt_longer = 0;
	int ans_first = 0;
	int ans_second = 0;
	for (int i = 0;i < n;++i) {
		if (s[i] == '_') {
			ans_first = max(ans_first, cnt_longer);
			cnt_longer = 0;
		}
		else if (s[i] == '(') {
			ans_first = max(ans_first, cnt_longer);
			cnt_longer = 0;
			i++;
			bool next_ok = false;
			while (true) {
				if (s[i] == ')') {
					if (next_ok == true) ans_second++;
					next_ok = false;
					goto ppp;
				}
				else if (s[i] == '_') {
					if (next_ok == true) ans_second++;
					next_ok = false;
				}
				else {
					next_ok = true;
				}
				i++;
			}
		}else if(s[i] != ')'){
			cnt_longer++;
		}
	ppp:;
	}
	cout << max(ans_first,cnt_longer) << " " << ans_second << endl;
	return 0;
}