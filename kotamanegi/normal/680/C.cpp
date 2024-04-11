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
#define LONG_INF 8000000000000000000
int primes[1000] = {};
int main(){
	for (int i = 2;i <= 100;++i) {
		if (primes[i] == false) {
			for (int q = 2;q*i <= 100;++q) {
				primes[i*q] = true;
			}
		}
	}
	for (int i = 2;i <= sqrt(100);++i) {
		if (primes[i] == false) {
			cout << i << endl;
			string s;
			cin >> s;
			if (s == "yes") {
				for (int q = 2;q <= 100 / i;++q) {
					if (primes[q] == false) {
						cout << i*q << endl;
						string b;
						cin >> b;
						if (b == "yes") {
							cout << "composite" << endl;
							return 0;
						}
					}
				}
				cout << "prime" << endl;
				return 0;
			}
		}
	}
	cout << "prime" << endl;
	return 0;
}