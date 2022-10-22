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
map<long long, long long> del;
int main() {
	long long b, q, l, m;
	cin >> b >> q >> l >> m;
	REP(i, m) {
		long long tmp;
		cin >> tmp;
		del[tmp] = true;
	}
	if (b == 0) {
		if (del[0] == false) {
			cout << "inf" << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	if (llabs(b) > l) {
		cout << 0 << endl;
		return 0;
	}
	if (q == 0) {
		if (del[0] == false) {
			cout << "inf" << endl;
			return 0;
		}
		if (del[b] == false) {
			cout << 1 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	if (q == 1) {
		if (del[b] == false) {
			cout << "inf" << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	else if (q == -1) {
		if (del[b] == false || del[b*q] == false) {
			cout << "inf" << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	while (true) {
		if (llabs(b) > l) break;
		if (del[b] == false) ans++;
		b *= q;
	}
	cout << ans << endl;
	return 0;
}