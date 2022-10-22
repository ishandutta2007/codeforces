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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
long long n, k, s, t;
vector<pair<long long, long long>> car;
vector<int> kyori;
bool deter(long long a) {
	long long time = 0;
	for (int i = 0;i < k+1;++i) {
		if (kyori[i] > a) return false;
		if (kyori[i] * 2 <= a) {
			time += kyori[i];
		}
		else {
			time += kyori[i] * 2;
			time -= a - kyori[i];
		}
	}
	if (time <= t) return true;
	return false;
}
int main() {
	iostream::sync_with_stdio(false);
	cin >> n >> k >> s >> t;
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		car.push_back(make_pair(a, b));
	}
	long long final_dist = 0;
	vector<long long> p;
	REP(i, k) {
		long long a;
		cin >> a;
		p.push_back(a);
		final_dist += a;
	}
	p.push_back(0);
	sort(p.begin(),p.end());
	for (int i = 1;i < k + 1;++i) {
		kyori.push_back(p[i] - p[i - 1]);
	}
	kyori.push_back(s - p[k]);
	long long need_nenpi = 0;
	long long top = 10000000000;
	long long bot = 0;
	while (top - bot > 1) {
		long long mid = (top + bot) / 2;
		if (deter(mid)) {
			top = mid;
		}
		else {
			bot = mid;
		}
	}
	if (deter(bot)) {
		need_nenpi = bot;
	}
	else if(deter(top)){
		need_nenpi = top;
	}else{
		cout << "-1" << endl;
		return 0;
	}
	long long answer = 10000000000;
	for (int i = 0;i < car.size();++i) {
		if (need_nenpi <= car[i].second) {
			answer = min(answer, car[i].first);
		}
	}
	if(answer != 10000000000)
	cout << answer << endl;
	else cout << "-1" << endl;
	return 0;
}