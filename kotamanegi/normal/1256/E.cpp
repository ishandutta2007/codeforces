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
pair<long long, long long> cuts[3][300000];
long long ans[300000];
int main(){
#define int long long
	int n;
	cin >> n;
	vector<pair<int, int>> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(make_pair(a, i));
	}
	sort(inputs.begin(), inputs.end());
	REP(i, 3) {
		REP(q, 300000) {
			cuts[i][q].first = LONG_INF;
		}
	}
	cuts[2][0].first = -inputs[0].first;
	cuts[2][0].second = 0;
	for (int i = 0; i < inputs.size(); ++i) {
		for (int q = 0; q <= 2; ++q) {
			int next_go = max((long long)0, q - 1);
			if (cuts[next_go][i + 1].first > cuts[q][i].first) {
				cuts[next_go][i + 1] = cuts[q][i];
			}
		}
		int hoge = inputs[i].first;
		if (i != inputs.size() - 1) {
			hoge -= inputs[i + 1].first;
		}
		hoge += cuts[0][i].first;
		cuts[2][i + 1].first = hoge;
		cuts[2][i + 1].second = -1;
		REP(q, 3) {
			cuts[q][i + 1].second++;
		}
	}
	cout << cuts[2][inputs.size()].first << " ";
	vector<int> going;
	int hoge = inputs.size() - 1;
	while (hoge >= 0) {
		going.push_back(hoge);
		int tmp = cuts[0][hoge].second + 1;
		for (int j = 0; j < tmp; ++j) {
			ans[inputs[hoge - j].second] = going.size();
		}
		hoge -= cuts[0][hoge].second + 1;
	}
	cout << going.size() << endl;
	REP(i, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}