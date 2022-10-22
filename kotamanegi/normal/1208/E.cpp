/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
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
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
long long dp[3000000] = {};
priority_queue<pair<int, int>> now;
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n, w;
	cin >> n >> w;
	vector<vector<int>> inputs;
	REP(i, n) {
		vector<int> go;
		int tmp;
		cin >> tmp;
		REP(q, tmp) {
			int hoge;
			cin >> hoge;
			go.push_back(hoge);
		}
		inputs.push_back(go);
	}
	REP(i, n) {
		/*
		if (inputs[i].size() == w) {
			dp[0] += inputs[i][0];
			for (int q = 1; q < inputs.size(); ++q) {
				dp[q] += inputs[i][q] - inputs[i][q - 1];
			}
			continue;
		}
		*/
		now.push(make_pair(0, -1));
		int tea = 0;
		int now_itr = -1;
		REP(q, w) {
			if (q < inputs[i].size()) {
				if (inputs[i][q] - now.top().first >= 0) {
					dp[q] += inputs[i][q] - now.top().first;
				}
				now.push(make_pair(inputs[i][q], q));
			}
			else if (q == inputs[i].size()) {
				if (0 - now.top().first >= 0) {
					dp[q] += 0 - now.top().first;
				}
				now.push(make_pair(0, 1e9));
			}
			else if (w - inputs[i].size() > q+1) {
				q = w - inputs[i].size() - 1;
			}
			if (w - inputs[i].size() <= q) {
				now_itr++;
			}
			while (now.top().second < now_itr) {
				pair<int, int> geko = now.top();
				now.pop();
				int bobo = now.top().first;
				dp[q] += bobo - geko.first;
			}
		}
		while (now.empty() == false) {
			now.pop();
		}
	}
	for (int i = 0; i < w; ++i) {
		cout << dp[i] << " ";
		dp[i + 1] += dp[i];
	}
	cout << endl;
}