#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <list>
#include <typeinfo>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
map<int, int> x_remain;
map<int, int> y_remain;
map<pair<int, int>, int> bad;
int main() {
	int n;
	scanf("%d", &n);
	long long ans = 0;
	REP(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans += x_remain[x];
		ans += y_remain[y];
		x_remain[x]++;
		y_remain[y]++;
		ans -= bad[pair<int, int>(x, y)];
		bad[pair<int, int>(x, y)]++;
	}
	cout << ans << endl;
}
//thank you for reading my code!