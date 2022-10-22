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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
int main() {
#define int long long
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> inputs;
	REP(i, m) {
		long long a;
		cin >> a;
		a--;
		inputs.push_back(a);
	}
	inputs.push_back(3e18);
	sort(inputs.begin(), inputs.end());
	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		long long now_page = (inputs[i] - i) / k;
		int q;
		for (q = i + 1; q < inputs.size(); ++q) {
			long long nya_page = (inputs[q] - i) / k;
			if (now_page != nya_page) break;
		}
		i = q - 1;
		ans++;
	}
	cout << ans << endl;
	return 0;
}