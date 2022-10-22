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
int main(){
	int a, b;
	cin >> a >> b;
	vector<int> hoge;
	REP(i, a) {
		int tmp;
		cin >> tmp;
		hoge.push_back(tmp);
	}
	b--;
	int cnt = 0;
	for (int i = 1;i <= min(a - b-1, b);++i) {
		if (hoge[b + i] == hoge[b - i]) {

		}
		else {
			hoge[b - i] = 0;
			hoge[b + i] = 0;
		}
	}
	for (int i = 0;i < a;++i) {
		cnt += hoge[i];
	}
	cout << cnt << endl;
	return 0;
}