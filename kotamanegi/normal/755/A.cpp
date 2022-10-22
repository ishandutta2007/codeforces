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
int main() {
	int n;
	cin >> n;
	for (int i = 1;i >= 0;++i) {
		int poa = i*n + 1;
		if (poa >= 5) {
			bool hogee = false;
			for (int q = 2;q <= sqrt(poa);++q) {
				if (poa % q == 0) hogee = true;
			}
			if (hogee == true) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}