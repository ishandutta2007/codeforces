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
pair<long long, long long> go[300000];
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	long long now = 0;
	long long now_max = 0;
	long long now_itr = 0;
	for (int i = 0; i < n; ++i) {
		now += inputs[n-1-i];
		if (i >= k) {
			now -= inputs[n - 1 - i + k];
		}
		if (now_max <= now) {
			now_max = now;
			now_itr = n - i;
		}
		go[n - 1 - i] = make_pair(now_max, now_itr);
	}
	pair<int, int> final_go;
	int final_ans = 0;
	now = 0;
	for(int i = 0;i < n;++i){
		now += inputs[i];
		if (i >= k) {
			now -= inputs[i - k];
		}
		if (now + go[i + 1].first > final_ans) {
			final_ans = now + go[i + 1].first;
			final_go = make_pair(i - k + 2, go[i + 1].second);
		}
	}
	cout << final_go.first << " " << final_go.second << endl;
}