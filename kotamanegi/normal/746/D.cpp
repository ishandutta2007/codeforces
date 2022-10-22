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
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	string ans;
	int now_cnt = 1;
	if (a < b) {
		ans.push_back('B');
		b--;
	}
	else {
		ans.push_back('G');
		a--;
	}
	for (int i = 1;i < n;++i) {
		if (a < b) {
			if (now_cnt == k) {
				if (ans[ans.size() - 1] == 'B') {
					ans.push_back('G');
					a--;
				}
				else {
					b--;
					ans.push_back('B');
				}
				now_cnt = 1;
			}else{
				b--;
				ans.push_back('B');
				if (ans[ans.length() - 1] != ans[ans.length() - 2]) now_cnt = 0;
				now_cnt++;
			}
		}
		else {
			if (now_cnt == k) {
				if (ans[ans.size() - 1] == 'B') {
					ans.push_back('G');
					a--;
				}
				else {
					b--;
					ans.push_back('B');
				}
				now_cnt = 1;
			}else {
				a--;
				ans.push_back('G');
				if (ans[ans.length() - 1] != ans[ans.length() - 2]) now_cnt = 0;
				now_cnt++;
			}
		}
	}
	if (a == 0 && b == 0) {
		cout << ans << endl;
		return 0;
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
}