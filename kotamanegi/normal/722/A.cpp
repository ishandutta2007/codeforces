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
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	if (a[3] >= '6') {
		a[3] = '0';
	}
	if (n == 24) {
		if (a[0] > '2') {
			a[0] = '0';
		}
		else if (a[0] == '2'&&a[1] > '3') {
			a[1] = '1';
		}
	}
	else {
		if (a[0] != '1' && a[0] != '0') {
			if (a[1] != '0') {
				a[0] = '0';
			}
			else {
				a[0] = '1';
			}
		}
		if (a[0] == '1') {
			if (a[1] > '2') {
				a[1] = '0';
			}
		}
		else if (a[1] == '0') {
			a[1] = '1';
		}
	}
	std::cout << a << endl;
	return 0;
}