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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
map<pair<long long, long long>, long long> memo;
long long power(long long a,long long now) {
	if (memo[make_pair(a, now)]) return memo[make_pair(a, now)];
	long long ans = 1;
	pair<int, int> base = make_pair(a, now);
	while (now != 0) {
		if (now % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		now /= 2;
		a *= a;
		a %= MOD;
	}
	return memo[base] = ans;
}
long long inv(long long a) {
	return power(a, MOD - 2);
}
long long permutation(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
	}
	return ans;
}
long long combination(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
		ans *= inv(i + 1);
		ans %= MOD;
	}
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		for (int i = 0; i < n-1; ++i) {
			cout << 1;
		}
		cout << 0 << endl;
		return 0;
	}
		int sizing = n - k;
		sizing /= 2;
		sizing++;
		for (int i = 0; i < n; ++i) {
			if (i % sizing == 0) {
				cout << "0";
			}
			else cout << "1";
		}
		cout << endl;
	return 0;
}
/*
int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> hoge;
	for (int i = 0; i < (1 << n); ++i) {
		string s;
		int now = i;
		for (int q = 0; q < n; ++q) {
			s.push_back(now%2 + '0');
			now /= 2;
		}
		map<pair<int,string>, int> appear;
		for (int q = 0; q < s.length(); ++q) {
			string gogo;
			for (int j = q; j < s.length(); ++j) {
				gogo.push_back(s[j]);
				appear[make_pair(j - q + 1,gogo)]++;
			}
		}
		int cnt = 100000;
		for (auto i = appear.begin(); i != appear.end(); ++i) {
			if (i->second == 1) {
				cnt = min(cnt, i->first.first);
				break;
			}
		}
		hoge.push_back(make_pair(cnt, s));
	}
	sort(hoge.begin(), hoge.end());
	for (int i = 0; i < hoge.size(); ++i) {
		if(hoge[i].first % 2 == n%2)
		cout << hoge[i].first << " " << hoge[i].second << endl;
	}
	return 0;
}

*/