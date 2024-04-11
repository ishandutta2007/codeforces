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
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
map<string, int> s;
int union_find_tree[200000] = {};
long long cost[200000] = {};
int union_find(int now) {
	if (union_find_tree[now] == now) return now;
	return union_find_tree[now] = union_find(union_find_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_find_tree[a] = b;
	return 0;
}
int main() {
	iostream::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	REP(i, a) {
		string a;
		cin >> a;
		s[a] = i;
	}
	for (int i = 0; i <= a; ++i) {
		union_find_tree[i] = i;
	}
	REP(i, a) {
		cin >> cost[i];
	}
	REP(i, b) {
		int a;
		cin >> a;
		int hoget = -1;
		for (int q = 0; q < a; ++q) {
			int tmp;
			cin >> tmp;
			tmp--;
			if (hoget == -1) {
				hoget = tmp;
			}
			else {
				union_merge(tmp,hoget);
				cost[hoget] = min(cost[hoget], cost[tmp]);
			}
		}
	}
	long long ans = 0;
	REP(i, c) {
		string d;
		cin >> d;
		ans += cost[union_find(s[d])];
	}
	cout << ans << endl;
	return 0;
}