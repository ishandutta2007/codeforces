#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <list>
#include <typeinfo>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0;i < 10001;++i) {
		if (c - a*i < 0) break;
		if ((c - a*i) % b == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
//thank you for reading my code!