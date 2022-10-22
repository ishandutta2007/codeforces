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
long long bo[50] = {};
int main() {
	long long x, d;
	cin >> x >> d;
	bo[1] = 1;
	for (int i = 2; i < 50; ++i) {
		bo[i] = bo[i - 1] * 2LL;
		bo[i - 1]--;
	}
	vector<long long> ans;
	long long cnt = 1;
	while (x != 0) {
		for (int i = 49; i >= 1; --i) {
			if (bo[i] <= x) {
				x -= bo[i];
				for (int q = 0; q < i-1; ++q) {
					ans.push_back(cnt);
				}
				cnt += 100000 + 10 * d;
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " " << endl;
	}
	return 0;
}