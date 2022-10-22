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
int grid[500][500];
int main(){
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		REP(q, n) {
			cin >> grid[i][q];
		}
	}
	int ans = m;
	vector<int> inputs;
	REP(q, m) {
		inputs.push_back(q + 1);
	}
	for (int i = 0; i < n-1; ++i) {
		vector<pair<int, int>> go;
		REP(q, m) {
			go.push_back(make_pair(grid[q][i] - grid[q][n - 1], q+1));
		}
		go.push_back(make_pair(-1e9, -1));
		sort(go.begin(), go.end());
		reverse(go.begin(), go.end());
		int now = 0;
		for (int q = 0; q < go.size(); ++q) {
			now += go[q].first;
			if (now < 0) {
				vector<int> popo;
				for (int j = q; j < go.size() - 1; ++j) {
					popo.push_back(go[j].second);
				}
				if (popo.size() < inputs.size()) {
					inputs = popo;
				}
				break;
			}
		}
	}
	cout << inputs.size() << endl;
	REP(i, inputs.size()) {
		cout << inputs[i] << " ";
	}
	cout << endl;
}