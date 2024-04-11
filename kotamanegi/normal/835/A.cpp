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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include<fstream>
#include <unordered_map>  
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define f(n) for(int i=0;i<n;++i)
#define REP(i,n) for(long long i = 0;i < n;++i) 
int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int first = a*b + 2 * d;
	int second = a*c + 2 * e;
	if (first == second) {
		cout << "Friendship" << endl;
	}
	else if (first < second) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
	return 0;
}