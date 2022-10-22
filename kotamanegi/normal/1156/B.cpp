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
#include <random>
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
#include <omp.h>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
vector<int> nya;
int n, m;
int solve(int start_line) {
	int border_line = start_line;
	int ans = 1;
	for (int i = 0; i < border_line; ++i) {
		while (start_line < nya.size() && nya[start_line] - nya[i] < m) {
			start_line++;
		}
		if (start_line == nya.size()) return 0;
		start_line++;
		ans++;
	}
	return ans;
}
int main() {
	int test_case;
	cin >> test_case;
	REP(ta, test_case) {
		string s;
		cin >> s;
		int cnt[120] = {};
		for (int i = 0; i < s.length(); ++i) {
			cnt[s[i] - 'a']++;
		}
		int ok = 1;
		for (int i = 1; i < s.length(); ++i) {
			if (abs(s[i] - s[i - 1]) == 1) {
				ok = 0;
				break;
			}
		}
		if (ok == 1) {
			cout << s << endl;
			continue;
		}
		string ans = "No answer";
		for (int i = 0; i < 30; i += 2) {
			if (cnt[i] != 0) {
				int ok = -1;
				for (int q = 1; q < 30; q += 2) {
					if (abs(i - q) != 1 && cnt[q] != 0) {
						ok = q;
						break;
					}
				}
				if (ok != -1) {
					ans.clear();
					for (int q = 0; q < 30; q += 2) {
						if (i != q) {
							for (int j = 0; j < cnt[q]; ++j) {
								ans.push_back(q + 'a');
							}
						}
					}
					for (int j = 0; j < cnt[i]; ++j) {
						ans.push_back(i + 'a');
					}
					for (int j = 0; j < cnt[ok]; ++j) {
						ans.push_back(ok + 'a');
					}
					for (int q = 1; q < 30; q += 2) {
						if (q != ok) {
							for (int j = 0; j < cnt[q]; ++j) {
								ans.push_back(q + 'a');
							}
						}
					}
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}