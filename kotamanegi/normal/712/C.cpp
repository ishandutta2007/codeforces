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
int x, y;
int hoge[3] = {};
int wa = 0;
int ans = 0;
int check() {
	for (int i = 0;i < 3;++i) {
		if (hoge[i] != x) return 0;
	}
	return 1;
}
int main() {
	cin >> x >> y;
	if (x < y) swap(x, y);
	REP(i, 3) hoge[i] = y;
	wa = 3 * y;
	while (check() == 0) {
		for (int i = 0;i < 3;++i) {
			if (hoge[i] != x) {
				wa -= hoge[i];
				if (wa - 1 > hoge[i]) {
					hoge[i] = min(wa - 1, x);
					wa += hoge[i];
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}