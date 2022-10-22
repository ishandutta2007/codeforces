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
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> a;
	REP(i, n) {
		int hoge;
		cin >> hoge;
		a.push_back(make_pair(hoge,i+1));
	}
	sort(a.begin(), a.end());
	for (int i = 0;i < a.size()/2;++i) {
		cout << a[i].second << " " << a[a.size() - 1 - i].second << endl;
	}
	return 0;
}