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
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int whereis = 0;
	int cnt = 1000000;
	for (int i = 0;i < t.size() - s.size()+1;++i) {
		int hoge = 0;
		for (int q = 0;q < s.size();++q) {
			if (t[i + q] != s[q]) hoge++;
		}
		if (cnt > hoge) {
			cnt = hoge;
			whereis = i;
		}
	}
	cout << cnt << endl;
	for (int q = 0;q < s.size();++q) {
		if (t[whereis + q] != s[q]) {
			cout << q + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}