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
char good[6] = { 'a','e','i','o','u','y' };
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cin.ignore();
	for (int i = 0;i < n;++i) {
		string wow;
		getline(cin, wow);
		int cnt = 0;
		for (int q = 0;q < wow.length();++q) {
			for (int j = 0;j < 6;++j) {
				if (wow[q] == good[j]) cnt++;
			}
		}
		if (cnt != a[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}