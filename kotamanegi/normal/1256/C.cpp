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
int go[1000000] = {};
int main() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> inputs;
	int summing = 0;
	REP(i, m) {
		int a;
		cin >> a;
		summing += a;
		inputs.push_back(a);
	}
	int next_n = -1;
	for (int i = 0; i < inputs.size(); ++i) {
		next_n += d-1;
		for (int q = 0; q < inputs[i]; ++q) {
			next_n++;
			go[next_n] = i + 1;
		}
	}
	if (n - next_n > d) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int shrink = next_n - n + 1;
	int now_itr = -1;
	int cnt = n;
	while(cnt != 0){
		now_itr++;
		if (go[now_itr] == 0) {
			if (shrink > 0) {
				shrink--;
				continue;
			}
		}
		cout << go[now_itr] << " ";
		cnt--;
	}
	cout << endl;
}