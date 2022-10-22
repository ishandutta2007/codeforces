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
	string n;
	long long k;
	cin >> n >> k;
	int cnt = 0;
	int deletee = 0;
	for (int i = n.length() - 1;i >= 0;--i) {
		if (n[i] != '0') {
			deletee++;
		}
		else cnt++;
		if (cnt >= k) {
			cout << deletee << endl;
			return 0;
		}
	}
	for (int i = 0;i < n.length();++i) {
		if (n[i] == '0') {
			cout << n.length() - 1 << endl;
			return 0;
		}
	}
	cout << n.length() << endl;
	return 0;
}