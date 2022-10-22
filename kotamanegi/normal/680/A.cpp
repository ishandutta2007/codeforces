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
	vector<int> a;
	int ans = 0;
	REP(i, 5) {
		int b;
		cin >> b;
		ans += b;
		a.push_back(b);
	}
	sort(a.begin(), a.end(), greater<int>());
	int neko = 0;
	for (int i = 0;i < 4;++i) {
		if (a[i] == a[i + 1]) {
			if (i < 3 && a[i + 1] == a[i + 2]) {
				neko = max(neko, a[i] * 3);
			}
			else {
				neko = max(neko, a[i] * 2);
			}
		}
	}
	cout << ans - neko << endl;
	return 0;
}