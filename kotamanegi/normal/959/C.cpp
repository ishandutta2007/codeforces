#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 6) cout << -1 << endl;
	else {
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "2 4" << endl;
		for (int i = 5; i <= n; ++i) {
			cout << "1 " << i << endl;
		}
	}
	for (int i = 1; i < n; ++i) {
		cout << i << " " << i + 1 << endl;
	}
	return 0;
}