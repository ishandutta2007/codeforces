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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main(){
	string a, b;
	cin >> a >> b;
	map<int, int> wow;
	REP(i, a.length()) {
		wow[a[i]-'0']++;
	}
	if (a.length() < b.length()) {
		for (int i = 9;i >= 0;--i) {
			for (int q = 0;q < wow[i];++q) {
				cout << i;
			}
		}
		cout << endl;
		return 0;
	}
	long long ans = 0;
	string now;
	for (int i = 0;i < b.length();++i) {
		string w = now;
		map<int, int> mew = wow;
		if (b[i] != '0') {
			for (int q = b[i] - '1';q >= 0;--q) {
				if (wow[q] != 0) {
					mew[q]--;
					w.push_back(q + '0');
					break;
				}
			}
		}
		for (int q = 9;q >= 0;--q) {
			for (int j = 0;j < mew[q];++j) {
				w.push_back(q + '0');
			}
		}
		if (w <= b&&w.length() == b.length()) ans = max(ans,stoll(w));
		if (wow[b[i]-'0'] == 0) break;
		wow[b[i]-'0']--;
		now.push_back(b[i]);
	}
	if (now.empty() ==false&&now <= b) {
		ans = max(ans, stoll(now));
	}
	cout << ans << endl;
	return 0;
}