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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
	string a, b;
	cin >> a >> b;
	string ans = "zzzzzzzzzzzzzzzzzzzzz";
	string c;
	for (int q = 0;q < a.length();++q) {
		c += a[q];
		string d;
		for (int j = 0;j < b.length();++j) {
			d += b[j];
			ans = min(ans, c + d);
		}
	}
	cout << ans << endl;
	return 0;
}