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
int main() {
	long long n;
	cin >> n;
	vector<long long> ans;
	long long maxium = 0;
	for (int i = 2;i <= n + 1;++i) {
		long long cnter = 1;
		long long downer = i;
		long long a = 2;
		while (a <= sqrt(downer)) {
			if (downer % a == 0) {
				downer /= a;
				a++;
				cnter++;
			}
			else {
				a++;
			}
		}
		cnter = min(cnter, (long long)2);
		ans.push_back(cnter);
		maxium = max(maxium, cnter);
	}
	cout << maxium << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}