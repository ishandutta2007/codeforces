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
long long segment_tree[1000000] = {};
int setter(int now_here,int counter) {
	if (now_here == 0) return segment_tree[0];
	if (counter == 0) {
		if (now_here % 2 == 0) {
			segment_tree[(now_here-1) / 2] = segment_tree[now_here] | segment_tree[now_here - 1];
		}
		else {
			segment_tree[(now_here-1) / 2] = segment_tree[now_here] | segment_tree[now_here + 1];
		}
	}
	else {
		if (now_here % 2 == 0) {
			segment_tree[(now_here-1) / 2] = segment_tree[now_here] ^ segment_tree[now_here - 1];
		}
		else {
			segment_tree[(now_here-1) / 2] = segment_tree[now_here] ^ segment_tree[now_here + 1];
		}
	}
	counter++;
	int hoge = segment_tree[(now_here)-1 / 2];
	return setter((now_here-1) / 2, counter % 2);
}
int main() {
	int n, m;
	cin >> n >> m;
	int begining = (1 << n) - 1;
	for (int i = 0;i < (1<<n);++i) {
		cin >> segment_tree[begining + i];
		setter(begining + i, 0);
	}
	for (int i = 0;i < m;++i) {
		int a;
		cin >> a;
		cin >> segment_tree[begining + a - 1];
		cout << setter(begining + a - 1, 0) << endl;
	}
	return 0;
}