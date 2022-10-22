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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)

int must_be[1000000] = {};
vector<int> related[1000000];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b) swap(a, b);
		related[a].push_back(b);
	}
	int ans = 0;
	for (int i = n;i > 0;--i) {
		if (related[i].size() != 0) {
			if (must_be[i] == 2) {
				cout << "0" << endl;
				return 0;
			}
			must_be[i] = 1;
			for (int q = 0;q < related[i].size();++q) {
				if (must_be[related[i][q]] == 1) {
					cout << "0" << endl;
					return 0;
				}
				must_be[related[i][q]] = 2;
			}
		}
	}
	bool oned = false;
	for (int i = 1;i <= n;++i) {
		if (must_be[i] == 1) {
			oned = true;
		}
		else if (must_be[i] == 2 && oned == true) {
			cout << "0" << endl;
			return 0;
		}
	}
	for (int i = 1;i <= n;++i) {
		if (must_be[i] == 1) {
			for (int q = i;q > 0;--q) {
				if (must_be[q] == 2) break;
				if (must_be[q] == 0) ans++;
			}
			cout << ans + 1 << endl;
			return 0;
		}
	}
	cout << n-1 << endl;
}