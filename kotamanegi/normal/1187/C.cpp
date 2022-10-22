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
vector<long long> geko[26];
int upper_ba[2000];
int main(){
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> inputs;
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			for (int q = b - 1; q < c - 1; ++q) {
				upper_ba[q] = 1;
			}
		}
		else {
			inputs.push_back(make_pair(b-1, c-1));
		}
	}
	REP(i, inputs.size()) {
		int ok = 0;
		for (int q = inputs[i].first; q < inputs[i].second; ++q) {
			if (upper_ba[q] == 0) {
				ok = 1;
				break;
			}
		}
		if (ok == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	int now = 10000;
	cout << now;
	REP(i, n-1) {
		if (upper_ba[i] == 1) {
			now++;
		}
		else {
			now--;
		}
		cout << " " << now;
	}
	cout << endl;
}