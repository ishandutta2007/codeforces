#define _CRT_SECURE_NO_WARNINGS
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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	long long l[2], r[2], k;
	cin >> l[0] >> r[0] >> l[1] >> r[1] >> k;
	long long max_ow = min(r[0], r[1]);
	long long min_ow = max(l[0], l[1]);
	long long ans = max_ow - min_ow;
	if (max_ow >= k&&min_ow <= k) {
		ans--;
	}
	if (ans < 0) {
		cout << "0" << endl;
		return 0;
	}
	cout << ans+1 << endl;
	return 0;
}