#define _CRT_SECURE_NO_WARNINGS
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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	int ans[2] = {};
	for (int i = 0;i < n;++i) {
		if (i % 7 == 0 || i % 7 == 1) ans[0]++;
		if (i % 7 == 5 || i % 7 == 6) ans[1]++;
	}
	cout << ans[1] << " " << ans[0] << endl;
}