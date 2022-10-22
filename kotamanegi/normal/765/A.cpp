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
#define LONG_INF 800000000000000000
map<pair<string, string>, int> cnt;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	string s;
	cin >> s;
	REP(i, n) {
		string hoge;
		cin >> hoge;
		string a;
		for (int i = 0;i < 3;++i) {
			a.push_back(hoge[i]);
		}
		string b;
		for (int i = 5;i < 8;++i) {
			b.push_back(hoge[i]);
		}
		if (a < b) swap(a, b);
		cnt[(make_pair(a, b))]++;
	}
	for (auto itr = cnt.begin();itr != cnt.end();++itr) {
		if ((itr->second) % 2 == 1) {
			cout << "contest" << endl;
			return 0;
		}
	}
	cout << "home" << endl;
	return 0;
}