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
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int A[300000];
int ans[300000];
vector<int> gogo[300000];
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n) {
		cin >> A[i];
		ans[i] = 1e7;
	}
	queue<int> next;
	REP(i, n) {
		if (i + A[i] < n) {
			gogo[i + A[i]].push_back(i);
			if (A[i + A[i]] % 2 != A[i] % 2) {
				ans[i] = 1;
				next.push(i);
			}
		}
		if (i - A[i] >= 0) {
			gogo[i - A[i]].push_back(i);
			if (A[i - A[i]] % 2 != A[i] % 2) {
				ans[i] = 1;
				next.push(i);
			}
		}
	}
	while (next.empty() == false) {
		int now = next.front();
		next.pop();
		REP(q, gogo[now].size()) {
			if (ans[gogo[now][q]] == 1e7) {
				ans[gogo[now][q]] = ans[now] + 1;
				next.push(gogo[now][q]);
			}
		}
	}
	REP(i, n) {
		if (i != 0) cout << " ";
		if (ans[i] == 1e7) ans[i] = -1;
		cout << ans[i];
	}
	cout << endl;
}