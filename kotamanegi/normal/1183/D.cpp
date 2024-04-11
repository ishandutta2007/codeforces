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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long bobo[300000] = {};
int main(){
	iostream::sync_with_stdio(false);
	int query;
	cin >> query;
	REP(i, query) {
		int n;
		cin >> n;
		REP(i, n) {
			bobo[i] = 0;
		}
		REP(i, n) {
			long long c;
			cin >> c;
			bobo[c - 1]++;
		}
		vector<long long> nexts;
		REP(i, n) {
			if (bobo[i] != 0) {
				nexts.push_back(bobo[i]);
			}
		}
		sort(nexts.begin(), nexts.end());
		long long ans = nexts[nexts.size() - 1];
		long long back = ans;
		for (int q = nexts.size() - 2; q >= 0; --q) {
			if (nexts[q] >= back) {
				back--;
				if (back <= 0) break;
				ans += back;
			}
			else {
				back = nexts[q];
				ans += back;
			}
		}
		cout << ans << endl;
	}
}