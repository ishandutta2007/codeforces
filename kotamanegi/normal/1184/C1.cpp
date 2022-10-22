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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> inputs;
	REP(i, n * 4 + 1) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(a, b));
	}
	for (int left_x = 0; left_x <= 50; ++left_x) {
		for (int right_x = left_x + 1; right_x <= 50; ++right_x) {
			REP(left_y, 51) {
				for (int right_y = left_y + 1; right_y < 51; ++right_y) {
					pair<int, int> cnt = {-1,-1};
					REP(q, inputs.size()) {
						if ((inputs[q].first >= left_x && inputs[q].first <= right_x) && (inputs[q].second == left_y || inputs[q].second == right_y)) {

						}
						else if ((inputs[q].first == left_x || inputs[q].first == right_x) && (inputs[q].second >= left_y && inputs[q].second <= right_y)) {

						}
						else {
							if (cnt.first == -1) {
								cnt = make_pair(inputs[q].first, inputs[q].second);
							}
							else {
								cnt = make_pair(-1, -1);
								break;
							}
						}
					}
					if (cnt.first != -1) {
						cout << cnt.first << " " << cnt.second << endl;
						return 0;
					}
				}
			}
		}
	}
}