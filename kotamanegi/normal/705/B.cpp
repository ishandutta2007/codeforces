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
	long long n;
	cin >> n;
	long long hoge = 0;
	REP(i, n) {
		long long a;
		cin >> a;
		hoge += a;
		hoge--;
		if (hoge % 2 == 0) {
			cout << "2" << endl;
		}
		else {
			cout << "1" << endl;
		}
	}

}