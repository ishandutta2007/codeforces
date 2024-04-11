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
	if (n <= 2) {
		cout << "-1" << endl;
		return 0;
	}
	n *= n;
	long long m, k;
	if (n % 2 == 1) {
		n--;
		m = n / 2;
		k = n / 2 + 1;
	}
	else {
		long long hoge = n / 4;
		m = hoge - 1;
		k = hoge + 1;
	}
	cout << m << " " << k << endl;
	return 0;
}