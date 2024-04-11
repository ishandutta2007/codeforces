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
long long gogo[200000] = {};
int main() {
	int n;
	cin >> n;
	vector<long long> wow;
	REP(i, n) {
		long long a;
		cin >> a;
		wow.push_back(a);
	}
	vector<long long> cal;
	REP(i, n - 1) {
		cal.push_back(llabs(wow[i] - wow[i + 1]));
	}
	//start from 0
	long long ans = 0;
	long long tmp = 0;
	long long itr = cal.size() - 1;
	if (cal.size() % 2 == 0) itr--;
	while (itr >= 1) {
		tmp -= cal[itr];
		itr--;
		tmp += cal[itr];
		gogo[itr] = tmp;
		itr--;
	}
	for (int i = cal.size() - 1;i >= 0;--i) {
		gogo[i] = max(gogo[i], gogo[i + 1]);
	}
	tmp = 0;
	for (int i = 0;i < cal.size();++i) {
		if (i % 2 == 0) tmp += cal[i];
		else if(i != cal.size() - 1)tmp -= cal[i];
	}
	for (int i = 0;i < cal.size();i += 2) {
		ans = max(ans,tmp + gogo[i + 1]);
		tmp -= cal[i];
		if (i + 1 < cal.size()) {
			tmp += cal[i+1];
		}
	}
	//start from 1
	if (cal.size() != 1) {
		cal.erase(cal.begin());
		for (int i = 0;i < 200000;++i) {
			gogo[i] = 0;
		}
		tmp = 0;
		itr = cal.size() - 1;
		if (cal.size() % 2 == 0) itr--;
		while (itr >= 1) {
			tmp -= cal[itr];
			itr--;
			tmp += cal[itr];
			gogo[itr] = tmp;
			itr--;
		}
		for (int i = cal.size() - 1;i >= 0;--i) {
			gogo[i] = max(gogo[i], gogo[i + 1]);
		}
		tmp = 0;
		for (int i = 0;i < cal.size();++i) {
			if (i % 2 == 0) tmp += cal[i];
			else if (i != cal.size() - 1)tmp -= cal[i];
		}
		for (int i = 0;i < cal.size();i += 2) {
			ans = max(ans, tmp + gogo[i + 1]);
			tmp -= cal[i];
			if (i + 1 < cal.size()) {
				tmp += cal[i + 1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}