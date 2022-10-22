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
#include <malloc.h>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	int s;
	cin >> s;
	vector<string> a;
	REP(i, s) {
		string tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0;i < a.size();++i) {
		if (a[i][0] == 'O'&&a[i][1] == 'O') {
			a[i][0] = '+';
			a[i][1] = '+';
			goto solved;
		}
		else if (a[i][3] == 'O'&&a[i][4] == 'O') {
			a[i][3] = '+';
			a[i][4] = '+';
			goto solved;
		}
	}
	cout << "NO" << endl;
	return 0;
solved:;
	cout << "YES" << endl;
	REP(i, a.size()) {
		cout << a[i] << endl;
	}
	return 0;
}