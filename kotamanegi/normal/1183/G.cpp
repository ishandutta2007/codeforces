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
long long winning[300000] = {};
int main() {
	iostream::sync_with_stdio(false);
	int query;
	cin >> query;
	REP(i, query) {
		int n;
		cin >> n;
		REP(i, n) {
			bobo[i] = 0;
			winning[i] = 0;
		}
		REP(i, n) {
			long long c,d;
			cin >> c >> d;
			bobo[c - 1]++;
			winning[c - 1] += d;
		}
		vector<pair<long long,long long>> nexts;
		REP(i, n) {
			if (bobo[i] != 0) {
				nexts.push_back(make_pair(bobo[i],winning[i]));
			}
		}
		sort(nexts.begin(), nexts.end(),greater<pair<long long,long long>>());
		long long ans = nexts[0].first;
		long long back = ans;
		vector<int> gogo;
		gogo.push_back(ans);
		for (int q = 1; q < nexts.size(); ++q) {
			if (nexts[q].first >= back) {
				back--;
				if (back <= 0) break;
				gogo.push_back(back);
				ans += back;
			}
			else {
				back = nexts[q].first;
				gogo.push_back(back);
				ans += back;
			}
		}
		nexts.push_back(make_pair(-1,0));
		int itr = 0;
		long long cnt = 0;
		priority_queue<long long> findings;
		for (int i = 0; i < gogo.size(); ++i) {
			while (gogo[i] <= nexts[itr].first) {
				findings.push(nexts[itr].second);
				itr++;
			}
			cnt += min(findings.top(),(long long)gogo[i]);
			findings.pop();
		}
		cout << ans << " " << cnt << endl;
	}
}