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
long long alreadying[100002] = {};
long long to_stringed(string n) {
	if (n.length() > 8||n[0] == '0') return -1;
	long long ans = 0;
	long long multi = 1;
	for (int i = n.length() - 1;i >= 0;--i) {
		if (n[i] >= '0'&&n[i] <= '9') {
			ans += multi * (n[i] - '0');
		}
		else return -1;
		multi *= 10;
	}
	return ans;
}
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<string, int>> wow;
	int cnt_example = 0;
	REP(i, n) {
		string a;
		cin >> a;
		int b;
		cin >> b;
		int c = to_stringed(a);
		if (c != -1 && c <= n) {
			alreadying[c] = b + 1;
		}
		else {
			wow.push_back(make_pair(a, b));
		}
		if (b == 1)cnt_example++;
	}
	int failed = 0;
	for (int i = 1;i <= n;++i) {
		if (i <= cnt_example) {
			if (alreadying[i] != 2) failed = true;
		}
		else {
			if (alreadying[i] != 1) failed = true;
		}
	}
	if (failed == 0) {
		cout << "0" << endl;
		return 0;
	}
	vector<pair<string, string>> answers;
	int safe_area = 0;
	for (int i = 1;i <= n;++i) {
		if (alreadying[i] == 0) {
			safe_area = i;
			break;
		}
	}
	if (safe_area == 0) {
		for (int t = 1;t <= n;++t) {
			if (alreadying[t] == 1) {
				safe_area = t;
				alreadying[t] = 0;
				break;
			}
		}
		answers.push_back(make_pair(to_string(safe_area),to_string(n+1)));
		wow.push_back(make_pair(to_string(n + 1), 0));
	}
	if (safe_area <= cnt_example) {
		int b = cnt_example;
		for (int t = 1;t <= cnt_example;++t) {
			if (alreadying[t] == 1) {
				while (true) {
					b++;
					if (b > n) goto ok;
					if (alreadying[b] == 2) {
						answers.push_back(make_pair(to_string(b), to_string(safe_area)));
						answers.push_back(make_pair(to_string(t), to_string(b)));
						alreadying[t] = 0;
						alreadying[safe_area] = 2;
						alreadying[b] = 1;
						safe_area = t;
						break;
					}
				}
			}
		}
	}
	else {
		int b = 0;
		for (int t = cnt_example+1;t <= n;++t) {
			if (alreadying[t] == 2) {
				while (true) {
					b++;
					if (b > n) goto ok;
					if (alreadying[b] == 1) {
						answers.push_back(make_pair(to_string(b), to_string(safe_area)));
						answers.push_back(make_pair(to_string(t), to_string(b)));
						alreadying[t] = 0;
						alreadying[safe_area] = 1;
						alreadying[b] = 2;
						safe_area = t;
						break;
					}
				}
			}
		}
	}
ok:;
	int b = cnt_example;
	for (int t = 1;t <= cnt_example;++t) {
		if (alreadying[t] == 1) {
			while (true) {
				b++;
				if (b > n) break;
				if (alreadying[b] == 0) {
					answers.push_back(make_pair(to_string(t), to_string(b)));
					alreadying[t] = 0;
					alreadying[b] = 1;
					safe_area = t;
					break;
				}
			}
		}
	}
	b = 0;
	for (int t = cnt_example + 1;t <= n;++t) {
		if (alreadying[t] == 2) {
			while (true) {
				b++;
				if (b > n) break;
				if (alreadying[b] == 0) {
					answers.push_back(make_pair(to_string(t), to_string(b)));
					alreadying[t] = 0;
					alreadying[b] = 2;
					safe_area = t;
					break;
				}
			}
		}
	}
	int left = 1;
	int right = cnt_example+1;
	for (int i = 0;i < wow.size();++i) {
		if (wow[i].second == 1) {
			while (true) {
				if (alreadying[left] == 0) {
					alreadying[left] = 2;
					answers.push_back(make_pair(wow[i].first, to_string(left)));
					break;
				}
				left++;
			}
		}
		else {
			while (true) {
				if (alreadying[right] == 0) {
					alreadying[right] = 2;
					answers.push_back(make_pair(wow[i].first, to_string(right)));
					break;
				}
				right++;
			}
		}
	}
	cout << answers.size() << endl;
	REP(i, answers.size()) {
		cout << "move " << answers[i].first << " " << answers[i].second << endl;
	}
	return 0;
}