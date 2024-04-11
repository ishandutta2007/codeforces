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
pair<int, int > ans[200000];
int main(){
	int n, m;
	cin >> n >> m;
	vector<tuple<int,int, int>> inputs;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		b ^= 1;
		inputs.push_back(make_tuple(a, b, i));
	}
	sort(inputs.begin(), inputs.end());
	int a = 1, b = 3;
	int now = 1;
	REP(i, inputs.size()) {
		if (get<1>(inputs[i]) == 0) {
			//use
			ans[get<2>(inputs[i])] = make_pair(now, now + 1);
			now++;
		}
		else {
			if (now < b) {
				cout << -1 << endl;
				return 0;
			}
			ans[get<2>(inputs[i])] = make_pair(a, b);
			if (b == a + 2) {
				b++;
				a = 1;
			}
			else a++;
		}
	}
	REP(i, m) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}