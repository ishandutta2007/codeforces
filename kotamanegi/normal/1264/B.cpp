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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int base_cnt[4];
int cnt[4];
int ok() {
	REP(q, 4) {
		if (cnt[q] != 0) return 0;
	}
	return 1;
}
int main() {
	iostream::sync_with_stdio(false);
	int summing = 0;
	REP(i, 4) {
		cin >> base_cnt[i];
		summing += base_cnt[i];
	}
	vector<int> ans;
	if (summing == 1) {
		cout << "YES" << endl;
		REP(i, 4) {
			if (base_cnt[i] == 1) {
				cout << i << endl;
			}
		}
		return 0;
	}
	{
		REP(q, 4) {
			cnt[q] = base_cnt[q];
		}
		if (cnt[0] != 0) {
			vector<int> tmp;
			tmp.push_back(0);
			cnt[0]--;
			while (true) {
				if (tmp.back() != 0) {
					if (cnt[tmp.back() - 1] != 0) {
						cnt[tmp.back() - 1]--;
						tmp.push_back(tmp.back() - 1);
						continue;
					}
				}
				if (tmp.back() != 3) {
					if (cnt[tmp.back() + 1] != 0) {
						cnt[tmp.back() + 1]--;
						tmp.push_back(tmp.back() + 1);
						continue;
					}
				}
				break;
			}
			if (ok() == 1) {
				ans = tmp;
			}
		}
	}
	{
		REP(q, 4) {
			cnt[q] = base_cnt[q];
		}
		if (cnt[1] != 0) {
			vector<int> tmp;
			tmp.push_back(1);
			cnt[1]--;
			while (true) {
				if (tmp.back() != 0) {
					if (cnt[tmp.back() - 1] != 0) {
						cnt[tmp.back() - 1]--;
						tmp.push_back(tmp.back() - 1);
						continue;
					}
				}
				if (tmp.back() != 3) {
					if (cnt[tmp.back() + 1] != 0) {
						cnt[tmp.back() + 1]--;
						tmp.push_back(tmp.back() + 1);
						continue;
					}
				}
				break;
			}
			if (ok() == 1) {
				ans = tmp;
			}
		}
	}
	{
		REP(q, 4) {
			cnt[q] = base_cnt[q];
		}
		if (cnt[3] != 0) {
			vector<int> tmp;
			tmp.push_back(3);
			cnt[3]--;
			while (true) {
				if (tmp.back() != 3) {
					if (cnt[tmp.back() + 1] != 0) {
						cnt[tmp.back() + 1]--;
						tmp.push_back(tmp.back() + 1);
						continue;
					}
				}
				if (tmp.back() != 0) {
					if (cnt[tmp.back() - 1] != 0) {
						cnt[tmp.back() - 1]--;
						tmp.push_back(tmp.back() - 1);
						continue;
					}
				}
				break;
			}
			if (ok() == 1) {
				ans = tmp;
			}
		}
	}
	{
		REP(q, 4) {
			cnt[q] = base_cnt[q];
		}
		if (cnt[2] != 0) {
			vector<int> tmp;
			tmp.push_back(2);
			cnt[2]--;
			while (true) {
				if (tmp.back() != 3) {
					if (cnt[tmp.back() + 1] != 0) {
						cnt[tmp.back() + 1]--;
						tmp.push_back(tmp.back() + 1);
						continue;
					}
				}
				if (tmp.back() != 0) {
					if (cnt[tmp.back() - 1] != 0) {
						cnt[tmp.back() - 1]--;
						tmp.push_back(tmp.back() - 1);
						continue;
					}
				}
				break;
			}
			if (ok() == 1) {
				ans = tmp;
			}
		}
	}
	if (ans.size() == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " ";
	}
	cout << endl;
}