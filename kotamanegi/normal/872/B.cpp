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
#define seg_size 524288
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> wow;
	REP(i, n) {
		long long a;
		cin >> a;
		wow.push_back(a);
	}
	if (k >= 3) {
		sort(wow.begin(), wow.end());
		cout << wow[wow.size() - 1] << endl;
		return 0;
	}
	if (k == 1) {
		sort(wow.begin(), wow.end());
		cout << wow[0] << endl;
		return 0;
	}
	else {
		cout << max(wow[0], wow[wow.size() - 1]) << endl;
		return 0;
	}
}