#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	double ans = n*m == 1 ? 1.0 : (1.0 / n + (1.0 * (m-1) * (n-1) / n / (n*m-1)));
	printf("%.9f\n", ans);
	return 0;
}