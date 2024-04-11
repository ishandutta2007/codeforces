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
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long deads[300000];
int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n;
	cin >> n;
	vector<long long> inputs;
	int cnt[2] = {};
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(a);
	}
	vector<long long> verdicts = inputs;
	vector<long long> final_ans;
	long long ans = 1e9;
	long long now = 0;
	vector<long long> dame;
	for (int i = 0; i < 70; ++i) {
		vector<long long> evens;
		vector<long long> odds;
		REP(q, n) {
			if (deads[q] == 1) continue;
			if (inputs[q] % 2 == 1) {
				odds.push_back(q);
			}
			else {
				evens.push_back(q);
			}
		}
		if (dame.size() + evens.size() < ans) {
			final_ans = dame;
			REP(q, evens.size()) {
				final_ans.push_back(verdicts[evens[q]]);
			}
			ans = final_ans.size();
		}
		REP(q, odds.size()) {
			deads[odds[q]] = 1;
			dame.push_back(verdicts[odds[q]]);
		}
		REP(q, evens.size()) {
			inputs[evens[q]] /= 2;
		}
	}
	cout << ans << endl;
	REP(q, final_ans.size()) {
		if (q != 0) cout << " ";
		cout << final_ans[q];
	}
	cout << endl;
}