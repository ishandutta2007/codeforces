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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 262144
long long lefts[200000] = {}, rights[200000] = {};
vector<long long> as,hogees;
int main() {
#define int long long
	int n;
	cin >> n;
	REP(i, 3) {
		int tmp;
		cin >> tmp;
		hogees.push_back(tmp);
	}
	REP(i, n) {
		int tmp;
		cin >> tmp;
		as.push_back(tmp);
	}
	if (n == 1) {
		cout << (hogees[0] + hogees[1] + hogees[2])*as[0] << endl;
		return 0;
	}
	lefts[0] = as[0];
	for (int i = 1;i < as.size();++i) {
		if (hogees[0] > 0) {
			lefts[i] = max(lefts[i - 1], as[i]);
		}
		else {
			lefts[i] = min(lefts[i - 1], as[i]);
		}
	}
	rights[as.size() - 1] = as[as.size() - 1];
	for (int i = as.size() - 2;i >= 0;--i) {
		if (hogees[2] > 0) {
			rights[i] = max(rights[i + 1], as[i]);
		}
		else {
			rights[i] = min(rights[i + 1], as[i]);
		}
	}
	long long ans = 0;
	for (int i = 0;i < as.size();++i) {
		long long geko = hogees[1] * as[i];
		geko += hogees[0] * lefts[i];
		geko += hogees[2] * rights[i];
		if (i == 0) {
			ans = geko;
		}
		ans = max(ans, geko);
	}
	cout << ans << endl;
	return 0;
}