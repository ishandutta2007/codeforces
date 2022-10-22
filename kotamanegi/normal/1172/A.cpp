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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 30000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(a,b) for(long long a = 0;a < b;++a)
int must_bedone[300000];
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a,b;
	REP(i,n) {
		int c;
		cin >> c;
		if (c != 0) {
			a.push_back(c);
		}
	}
	sort(a.begin(), a.end());
	REP(i, n) {
		int c;
		cin >> c;
		b.push_back(c);
	}
	int ans = n * 3;
	//first we simulate
	if (b[b.size() - 1] != 0) {
		//chance to be
		int gogo = b[b.size() - 1];
		int itr = b.size()-1;
		while (gogo > 0) {
			if (b[itr] != gogo) {
				gogo = -1;
				break;
			}
			else {
				gogo--;
				itr--;
			}
		}
		if (gogo != -1) {
			int next = b[b.size() - 1] + 1;
			REP(i, a.size()) {
				must_bedone[a[i]] = 1;
			}
			int tmp_ans = 0;
			while (next <= n) {
				if (must_bedone[next] == 0) {
					next = n + 2;
					break;
				}
				else {
					next++;
				}
				must_bedone[b[tmp_ans]] = 1;
				tmp_ans++;
			}
			if (next == n + 1) {
				ans = min(ans, tmp_ans);
			}
			for (int i = 1; i <= n; ++i) {
				must_bedone[i] = 0;
			}
		}
	}
	int now_taking = 1;
	REP(i, a.size()) {
		must_bedone[a[i]] = 1;
	}
	for (int i = 0; i <= 2 * n; ++i) {
		if (must_bedone[now_taking] == 1) {
			now_taking++;
			if (now_taking > n) {
				ans = min(ans, i + 1);
				break;
			}
		}
		if (i < b.size()) {
			must_bedone[b[i]] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}