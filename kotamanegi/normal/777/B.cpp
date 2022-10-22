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
int cnt_a[2][200] = {};
int cnt_b[2][200] = {};
int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	REP(q, 2)
		for (int i = 0;i < n;++i) {
			cnt_a[q][a[i] - '0']++;
			cnt_b[q][b[i] - '0']++;
		}
	int ans[2] = {};
	for (int i = 9;i >= 0;--i) {
		for (int q = i;q >= 0;--q) {
			if (cnt_b[0][i] >  cnt_a[0][q]) {
				cnt_b[0][i] -= cnt_a[0][q];
				cnt_a[0][q] = 0;
			}
			else {
				cnt_a[0][q] -= cnt_b[0][i];
				cnt_b[0][i] = 0;
			}
		}
	}
	for (int i = 0;i <= 9;++i) {
		ans[0] += cnt_a[0][i];
	}
	for (int i = 9;i >= 0;--i) {
		for (int q = i - 1;q >= 0;--q) {
			if (cnt_b[1][i] >  cnt_a[1][q]) {
				ans[1] += cnt_a[1][q];
				cnt_b[1][i] -= cnt_a[1][q];
				cnt_a[1][q] = 0;
			}
			else {
				ans[1] += cnt_b[1][i];
				cnt_a[1][q] -= cnt_b[1][i];
				cnt_b[1][i] = 0;
			}
		}
	}
	cout << ans[0] << endl;
	cout << ans[1] << endl;
	return 0;
}