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
int cnt[4] = {};
int main() {
	int n, k;
	cin >> n >> k;
	int remaining = n * 2;
	vector<int> inputs;
	REP(i, k) {
		int hoge;
		cin >> hoge;
		while (n > 0 && hoge >= 4) {
			hoge -= 4;
			n--;
		}
		if (n != 0) {
			inputs.push_back(hoge);
		}
		else {
			while (hoge >= 2) {
				inputs.push_back(2);
				hoge -= 2;
			}
			inputs.push_back(hoge);
		}
	}
	sort(inputs.begin(), inputs.end());
	while (inputs.empty() == false && inputs.back() == 3 && n > 0) {
		inputs.pop_back();
		n--;
	}
	REP(q, inputs.size()) {
		cnt[inputs[q]]++;
	}
	cnt[1] += cnt[3];
	cnt[2] += cnt[3];
	cnt[3] = 0;
	while (n > 0&&(cnt[1] != 0||cnt[2] != 0)) {
		if (cnt[1] == 0) {
			if (cnt[2] == 1) {
				cnt[2] = 0;
				break;
			}
			cnt[2] -= 2;
			cnt[1] += 2;
			cnt[1]--;
		}
		else {
			cnt[1]--;
			if (cnt[2] == 0) {
				cnt[1]--;
				cnt[1] = max(0, cnt[1]);
			}
			else {
				cnt[2]--;
			}
		}
		n--;
	}
	cnt[1] = max(cnt[1], 0);
	cnt[2] = max(cnt[2], 0);
	if (remaining >= cnt[1] + cnt[2]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}