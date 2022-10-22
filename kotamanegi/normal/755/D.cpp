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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
int main() {
	long long n, k;
	cin >> n >> k;
	if (n - k < k) k = n - k;
	long long now_ans = 1;
	long long now_cnt = 1;
	long long next_up = 0;
	long long now_where = 1;
	for (int i = 0;i < n;++i) {
		now_where += k;
		now_cnt += next_up;
		next_up = 0;
		if (now_where > n) {
			next_up = 1;
			now_where -= n;
			now_cnt++;
		}
		now_ans += now_cnt;
		if (i != n - 1) {
			cout << now_ans << " ";
		}
		else cout << now_ans - 1 << endl;
	}
	return 0;
}