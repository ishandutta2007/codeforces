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
	vector<int> wow;
	REP(i, 3) {
		int a;
		cin >> a;
		wow.push_back(a);
	}
	sort(wow.begin(), wow.end());
	if (wow[0] == 1 || (wow[0] == wow[1] && wow[0] == 2) || (wow[0] == wow[1] && wow[1] == wow[2] && wow[0] == 3)||(wow[0] == 2&&wow[1] == 4&&wow[2] == 4)) {
		cout << "YES" << endl;
		return 0;
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
}