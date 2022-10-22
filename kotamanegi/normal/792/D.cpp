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
#include<map>
#include <iomanip>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	long long n,k;
	cin >> n >> k;
	int leng = 0;
	while (n != 0) {
		leng++;
		n /= 2;
	}
	REP(test, k) {
		long long v;
		cin >> v;
		string compare;
		while (v != 0) {
			if (v % 2 == 1) {
				compare.push_back('1');
			}
			else compare.push_back('0');
			v /= 2;
		}
		for (int i = compare.length();i < leng;++i) {
			compare.push_back('0');
		}
		reverse(compare.begin(), compare.end());
		string s;
		cin >> s;
		for (int i = 0;i < s.length();++i) {
			if (s[i] == 'U') {
					for (int q = compare.length() - 1;q > 0;--q) {
						if (compare[q] == '1') {
							compare[q] = '0';
							compare[q - 1] = '1';
							goto ok;
						}
					}
			}
			else if (s[i] == 'R') {
				if (compare[compare.length() - 1] != '1') {
					for (int q = compare.length() - 2;q >= 0;--q) {
						if (compare[q] == '1') {
							compare[q + 1] = '1';
							goto ok;
						}
					}
				}
			}
			else if (s[i] == 'L') {
				if (compare[compare.length() - 1] != '1') {
					for (int q = compare.length() - 2;q >= 0;--q) {
						if (compare[q] == '1') {
							compare[q] = '0';
							compare[q + 1] = '1';
							goto ok;
						}
					}
				}
			}
		ok:;
		}
		long long final_ans = 0;
		long long nya = 1;
		for (int i = compare.length() - 1;i >= 0;--i) {
			if (compare[i] == '1') final_ans += nya;
			nya *= 2;
		}
		cout << final_ans << endl;
	}
	return 0;
}