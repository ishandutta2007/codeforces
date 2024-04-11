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
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		int a;
		cin >> a;
		map<int, int> wow;
		bool nya = false;
		REP(q, a) {
			int tmp;
			cin >> tmp;
			if (wow[-1 * tmp] == 1) {
				nya = true;
			}
			else wow[tmp] = 1;
		}
		if (nya == false) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}