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
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
	long long n;
	cin >> n;
	long long geko = 0;
	long long now = 9;
	while (geko + now <= n) {
		geko += now;
		now *= 10;
	}
	long long nya = n - geko;
	string a = to_string(geko);
	string b = to_string(nya);
	int ans = 0;
	for (int i = 0; i < a.length(); ++i) {
		ans += a[i] - '0';
	}
	REP(i, b.length()) {
		ans += b[i] - '0';
	}
	cout << ans << endl;
	return 0;
}