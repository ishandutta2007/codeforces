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
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans[2],final_ans;
	for (int i = 0;i < n;i++) {
		ans[i % 2].push_back(s[i]);
	}
	if (n % 2 == true) {
		reverse(ans[1].begin(),ans[1].end());
		cout << ans[1] << ans[0] << endl;
		return 0;
	}
	else {
		reverse(ans[0].begin(), ans[0].end());
		cout << ans[0] << ans[1] << endl;
		return 0;
	}
}