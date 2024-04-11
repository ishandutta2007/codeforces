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
#define LONG_INF 100000000000000
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	long long ans = 0;
	int hoge = min(a, min(c, d));
	a -= hoge;
	c -= hoge;
	d -= hoge;
	ans += 256 * hoge;
	hoge = min(b, a);
	ans += 32 * hoge;
	cout << ans << endl;
	return 0;
}