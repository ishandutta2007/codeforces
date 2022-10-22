#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
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
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
int main() {
#define int long long
	int n;
	cin >> n;
	long long a, b;
	cin >> a >> b;
	a += b;
	vector<long long> nya[2];
	REP(i, n) {
		long long c;
		cin >> c;
		nya[0].push_back(c);
	}
	REP(i, n) {
		long long c;
		cin >> c;
		nya[1].push_back(c);
	}
	vector<long long> calc;
	REP(i, n) {
		calc.push_back(abs(nya[1][i] - nya[0][i]));
	}
	for (int i = 0; i < a; ++i) {
		sort(calc.begin(), calc.end());
		if (calc[n - 1] == 0) {
			calc[n - 1] = 1;
		}
		else calc[n - 1]--;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += calc[i] * calc[i];
	}
	cout << ans << endl;
	return 0;
}