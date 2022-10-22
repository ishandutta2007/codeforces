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
int voel[5] = { 'a','e','o','i','u' };
vector<pair<int, string>> vertexs[20];
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		string s;
		cin >> s;
		int now_go = 0;
		int cnt = 0;
		REP(q, s.length()) {
			REP(j, 5) {
				if (s[q] == voel[j]) {
					now_go = j;
					cnt++;
				}
			}
		}
		vertexs[now_go].push_back(make_pair(cnt, s));
	}
	vector<pair<string, string>> go_back;
	vector<pair<int, string>> listings;
	vector<pair<string, string>> go_front;
	REP(i, 6) {
		sort(vertexs[i].begin(), vertexs[i].end());
		while (vertexs[i].size() >= 2) {
			int hoge = vertexs[i].size() - 1;
			if (vertexs[i][hoge - 1].first == vertexs[i][hoge].first) {
				if (i != 5) {
					go_back.push_back(make_pair(vertexs[i][hoge - 1].second, vertexs[i][hoge].second));
				}
				else {
					go_front.push_back(make_pair(vertexs[i][hoge - 1].second, vertexs[i][hoge].second));
				}
				vertexs[i].pop_back();
			}
			else {
				if(i != 5)
				vertexs[5].push_back(vertexs[i][hoge]);
			}
			vertexs[i].pop_back();
		}
		if (vertexs[i].size() == 1) {
			vertexs[5].push_back(vertexs[i].back());
		}
	}
	while (go_front.size() < go_back.size()) {
		go_front.push_back(go_back.back());
		go_back.pop_back();
	}
	cout << min(go_front.size(), go_back.size()) << endl;
	REP(i, min(go_front.size(), go_back.size())) {
		cout << go_front[i].first << " " << go_back[i].first << endl;
		cout << go_front[i].second << " " << go_back[i].second << endl;
	}
}