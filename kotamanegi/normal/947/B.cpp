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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main(){
#define int long long
	int n;
	cin >> n;
	vector<long long> snows;
	REP(i, n) {
		long long a;
		cin >> a;
		snows.push_back(a);
	}
	set<long long> foos;
	map<long long, long long> cnter;
	long long now_stock = 0;
	long long cnt = 0;
	REP(i, n) {
		foos.insert((snows[i]+now_stock));
		cnter[(snows[i] + now_stock)]++;
		cnt++;
		long long a;
		cin >> a;
		now_stock += a;
		long long ans = 0;
		while (cnt != 0&&*foos.begin() <= now_stock) {
			ans += cnter[*foos.begin()] * (*foos.begin() - (now_stock - a));
			cnt -= cnter[*foos.begin()];
			cnter[*foos.begin()] = 0;
			foos.erase(*foos.begin());
		}
		cout << ans + cnt * a << " ";
	}
	cout << endl;
	return 0;
}