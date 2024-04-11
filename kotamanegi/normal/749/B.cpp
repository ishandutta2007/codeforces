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
	pair<int, int> wow[3];
	REP(i, 3) {
		cin >> wow[i].first >> wow[i].second;
	}
	cout << "3" << endl;
	int hoge = wow[1].first - wow[0].first,hogehoge = wow[1].second - wow[0].second;
	cout << wow[2].first + hoge << " " << wow[2].second + hogehoge << endl;
	cout << wow[2].first - hoge << " " << wow[2].second - hogehoge << endl;
	hoge = wow[2].first - wow[0].first;
	hogehoge = wow[2].second - wow[0].second;
	cout << wow[1].first - hoge << " " << wow[1].second - hogehoge << endl;
	return 0;
}