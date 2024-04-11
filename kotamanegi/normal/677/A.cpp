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
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	int n, h;
	scanf("%d%d", &n, &h);
	long long ans = 0;
	REP(i, n) {
		int hh;
		scanf("%d", &hh);
		if (hh > h) {
			ans += 2;
		}
		else {
			ans += 1;
		}
	}
	cout << ans << endl;
}