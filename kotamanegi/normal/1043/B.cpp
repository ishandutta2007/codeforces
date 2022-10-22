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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
	int n;
	cin >> n;
	vector<int> a;
	int now = 0;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp - now);
		now = tmp;
	}
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		int bad = 0;
		for (int q = 0; q < n; ++q) {
			if (a[q % i] != a[q]) bad = 1;
		}
		if (bad == 0) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	cout << ans[0];
	REP(i, ans.size() - 1) {
		cout << " " << ans[i + 1];
	}
	cout << endl;
	return 0;
}