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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 262144
long long dp[300000];
int allowed[300000] = {};
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0;i < a.size();++i) {
		dp[a[i]]++;
	}
	int ans = 0;
	int itr = 0;
	for (int i = 0;i < n;++i) {
		if (dp[a[i]] > 1) {
			while (itr+1 < a[i]||allowed[a[i]] == true) {
				itr++;
				if (dp[itr] == 0) {
					dp[a[i]]--;
					ans++;
					dp[itr]++;
					a[i] = itr;
					goto ok;
				}
			}
			allowed[a[i]] = true;
		ok:;
		}
	}
	cout << ans << endl;
	REP(i, n) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}