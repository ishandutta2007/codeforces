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
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
map<int, int> wow;
int main(){
	int n;
	cin >> n;
	vector<int> a;
	REP(i, 2*n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	int ans = 0;
	int cnt = 0;
	for (int i = 0;i < a.size();++i) {
		if (wow[a[i]]) {
			wow[a[i]]--;
			cnt--;
		}
		else {
			wow[a[i]]++;
			cnt++;
			ans = max(cnt, ans);
		}
	}
	cout << ans << endl;
	return 0;
}