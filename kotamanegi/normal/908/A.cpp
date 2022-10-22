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
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
	string s;
	cin >> s;
	int ans = 0;
	string hoge = "aiueo";
	for (int i = 0;i < s.length();++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			if ((s[i] - '0') % 2 == 1)ans++;
		}
		else {
			for (int q = 0;q < 5;++q) {
				if (s[i] == hoge[q]) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}