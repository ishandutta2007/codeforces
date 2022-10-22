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
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 262144
struct hashing {
	typedef size_t result_type;
	size_t operator()(const string s) const;
};
inline std::size_t hashing::operator()(const string s) const {
	long long geko = 0;
	for (int i = 0;i < s.length();++i) {
		geko ^= (s[i] << ((i % 6) * 5));
	}
	return geko;
}
unordered_map<string, int, hashing> bads;
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> s;
	REP(i, n) {
		string a;
		cin >> a;
		s.push_back(a);
	}
	REP(i, n) {
		for (int q = 0;q < s[i].length();++q) {
			string now;
			for (int j = q;j < s[i].length();++j) {
				now.push_back(s[i][j]);
				if (bads[now] == 0 || bads[now] == i + 1) {
					bads[now] = i + 1;
				}
				else bads[now] = -1;
			}
		}
	}
	for (int i = 0;i < s.size();++i) {
		string final_ans = "11111111111";
		for (int q = 0;q < s[i].length();++q) {
			string now;
			for (int j = q;j < s[i].length();++j) {
				now.push_back(s[i][j]);
				if (bads[now] == i + 1) {
					if (final_ans.length() > now.length()) {
						final_ans = now;
					}
					break;
				}
			}
		}
		cout << final_ans << endl;
	}
	return 0;
}