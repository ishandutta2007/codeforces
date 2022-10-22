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
vector<int> can_go;
int main() {
	int n,t;
	cin >> n >> t;
	string s;
	cin >> s;
	int point_come = false;
	for (int i = 0;i < n;++i) {
		if (point_come == true) {
			if (s[i] >= '5') {
				can_go.push_back(i);
				goto task;
			}
		}else if (s[i] == '.') {
			point_come = true;
		}
	}
task:;
	if (can_go.size() == 0) {
		cout << s << endl;
		return 0;
	}
	int can_be_round = can_go[0];
	for (int i = 1;i < t;++i) {
		if (s[can_go[0] - i] == '.') {
			goto ok;
		}
		else {
			if (s[can_go[0] - i] == '4') {
				can_be_round = (can_go[0]) - i;
			}
			else {
				goto ok;
			}
		}
	}
ok:;
	string ans;
	for (int i = 0;i < n;++i) {
		if (s[i + 1] == '.') {
			if (can_be_round == i + 2) {
				ans.push_back(s[i]);
				for (int q = i;q >= 0;--q) {
					ans[q] += 1;
					if (ans[q] == '9' + 1) {
						ans[q] = '0';
					}
					else break;
				}
				goto  fia;
			}
			else ans.push_back(s[i]);
		}else{
			if (can_be_round == i + 1) {
				ans.push_back(s[i]+1);
				goto fia;
			}
			else {
				ans.push_back(s[i]);
			}
		}
	}
fia:;
	if (ans[0] != '0') {
		cout << ans << endl;
	}
	else {
		cout << "1" << ans << endl;
	}
	return 0;
}