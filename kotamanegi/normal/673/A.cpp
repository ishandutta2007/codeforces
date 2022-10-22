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
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int hoge[100000] = {};
int main() {
	int t;
	scanf("%d", &t);
	REP(i, t) {
		scanf("%d", &hoge[i]);
	}
	int counter = 0;
	for (int i = 1;i <= 90;++i) {
		counter++;
		for (int q = 0;q < t;++q) {
			if (i == hoge[q]) counter = 0;
		}
		if (counter >= 15) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "90" << endl;
	return 0;
}