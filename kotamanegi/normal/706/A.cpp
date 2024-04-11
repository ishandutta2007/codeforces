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
	int a, b;
	int n;
	cin >> a >> b >> n;
	double ans = -1;
	REP(i, n) {
		int x, y, v;
		cin >> x >> y >> v;
		double kyori = abs(x - a)*abs(x - a) + abs(y - b)*abs(y - b);
		kyori = sqrt(kyori);
		kyori /= v;
		if (i == 0) {
			ans = kyori;
		}
		else {
			ans = min(ans, kyori);
		}
	}
	cout <<fixed << setprecision(10)<<  ans << endl;
	return 0;
}