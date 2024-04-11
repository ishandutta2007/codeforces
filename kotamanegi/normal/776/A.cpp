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
int main() {
	string a, b;
	cin >> a >> b;
	cout << a << " " << b << endl;
	int n;
	cin >> n;
	REP(i, n) {
		string c, d;
		cin >> c >> d;
		if (a == c) {
			a = d;
		}
		else {
			b = d;
		}
		cout << a << " " << b << endl;
	}
	return 0;
}