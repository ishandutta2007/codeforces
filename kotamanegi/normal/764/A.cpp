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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 800000000000000000
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(int a, int b) {
	return a*b / gcd(a, b);
}
int main() {
	int n, m, z;
	cin >> n >> m >> z;
	int hoge = lcm(n, m);
	cout << z / hoge << endl;
	return 0;
}