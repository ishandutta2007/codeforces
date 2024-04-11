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
map<int,int> already_used;
int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> a;
	int think[2] = {};
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
		think[tmp % 2]++;
		already_used[tmp]++;
	}
	vector<long long> ans = a;
	int can_use = -1;
	int lol[2] = {0,-1};
	if (think[0] < think[1]) {
		can_use++;
	}
	for (int i = 0;i < n;++i) {
		if (think[0] > think[1]) {
			//odd < even
			if (ans[i] % 2 == 0) {
				can_use += 2;
				already_used[ans[i]]--;
				while (can_use <= m) {
					if (already_used[can_use] == 0) {
						ans[i] = can_use;
						already_used[can_use]++;
						think[1]++;
						think[0]--;
						goto ok;
					}
					can_use += 2;
				}
				cout << -1 << endl;
				return 0;
			}
		}
		else if (think[0] < think[1]) {
			//even < odd
			if (ans[i] % 2 == 1) {
				can_use += 2;
				already_used[ans[i]]--;
				while (can_use <= m) {
					if (already_used[can_use] == 0) {
						already_used[can_use]++;
						ans[i] = can_use;
						think[0]++;
						think[1]--;
						goto ok;
					}
					can_use += 2;
				}
				cout << -1 << endl;
				return 0;
			}
		}
		if (already_used[ans[i]] != 1) {
			lol[ans[i] % 2] += 2;
			already_used[ans[i]]--;
			while (lol[ans[i]%2] <= m) {
				if (already_used[lol[ans[i]%2]] == 0) {
					already_used[lol[ans[i]%2]] = 1;
					ans[i] = lol[ans[i]%2];
					goto gonow;
				}
				lol[ans[i]%2] += 2;
			}
			cout << "-1" << endl;
			return 0;
		gonow:;
		}
	ok:;
	}
	int real = 0;
	for (int i = 0;i < n;++i) {
		if (ans[i] != a[i]) {
			real++;
		}
	}
	cout << real << endl;
	for (int i = 0;i < n;++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}