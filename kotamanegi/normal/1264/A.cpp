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
int main() {
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(t, test_case) {
		int n;
		cin >> n;
		vector<int> inputs;
		int back = 0;
		cin >> back;
		int cnt = 1;
		REP(i, n-1) {
			int a;
			cin >> a;
			if (a != back) {
				inputs.push_back(cnt);
				cnt = 1;
				back = a;
			}
			else {
				cnt++;
			}
		}
		inputs.push_back(cnt);
		if (inputs.size() <= 2) {
			cout << "0 0 0" << endl;
			continue;
		}
		int now = 0;
		int i = 0;
		for (i = 0; i < inputs.size();++i) {
			now += inputs[i];
			if (now > n / 2) {
				i--;
				break;
			}
		}
		if (i <= 1) {
			cout << "0 0 0" << endl;
			continue;
		}
		int gold = inputs[0];
		int silver = 0;
		int bronze = 0;
		for (int q = 1; q <= i; ++q) {
			if (silver <= gold) {
				silver += inputs[q];
			}
			else {
				bronze += inputs[q];
			}
		}
		if (silver > gold&& bronze > gold) {
			cout << gold << " " << silver << " " << bronze << endl;
		}
		else {
			cout << "0 0 0" << endl;
		}
	}
}