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
	vector<int> hoge;
	int ans = 0;
	for (int i = 0;i < n;++i) {
		if (a[i] == 'W') {
			if (ans != 0) {
				hoge.push_back(ans);
				ans = 0;
			}
		}else{
			ans++;
		}
	}
	if (ans != 0) {
		hoge.push_back(ans);
	}
	cout << hoge.size() << endl;
	REP(i, hoge.size()) {
		cout << hoge[i] << " ";
	}
	cout << endl;
	return 0;
}