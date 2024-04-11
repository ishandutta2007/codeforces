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
	int n, k;
	cin >> n >> k;
	vector<int> hoge;
	for (int i = 0;i < n;++i) {
		string tmp;
		cin >> tmp;
		hoge.push_back(tmp.size());
	}
	string ans;
	cin >> ans;
	sort(begin(hoge), end(hoge));
	long long answ = 0;
	bool done = 0;
	for (int i = 0;i < n;++i) {
		answ += 1;
		if (hoge[i] > ans.length()) {
			answ--;
			if (i % k == 0) answ -= 5;
			cout << answ << endl;
			return 0;
		}
		if (hoge[i] == ans.length()) {
			if (done == 0) {
				cout << answ << " ";
				done = 1;
			}
		}
		if ((i + 1) % k == 0) answ += 5;
	}
	if (n%k == 0) {
		answ -= 5;
	}
	if (done == 0) {
		cout << answ << " ";
	}
	cout << answ << endl;
	return 0;
}