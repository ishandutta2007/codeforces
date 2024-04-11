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
int main(){
	int n, m;
	cin >> n >> m;
	char a;
	cin >> a;
	vector<string> inputs;
	REP(i, n) {
		string b;
		cin >> b;
		inputs.push_back(b);
	}
	int go[26] = {};
	REP(i, n) {
		REP(q, m) {
			if (inputs[i][q] == a) {
				int xe[4] = { 1,-1,0,0 };
				int ye[4] = { 0,0,1,-1 };
				REP(j, 4) {
					int now_x = xe[j] + i;
					int now_y = ye[j] + q;
					if (now_x >= 0 && now_y >= 0 && now_x < n && now_y < m) {
						if (inputs[now_x][now_y] != '.') go[inputs[now_x][now_y] - 'A'] = 1;
					}
				}
			}
		}
	}
	int ans = 0;
	REP(i, 26) {
		if((i + 'A') != a)
		ans += go[i];
	}
	cout << ans << endl;
}