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
#define int long long
	long long n, m, k;
	cin >> k >> n >> m;
	vector<pair<int, int>> firster;
	long long x, s;
	cin >> x >> s;
	REP(i, n) {
		int a;
		cin >> a;
		firster.push_back(make_pair(a, 0));
	}
	REP(i, n) {
		int a;
		cin >> a;
		firster[i].second = a;
	}
	firster.push_back(make_pair(x, 0));
	vector<pair<int, int>> seconder;
	seconder.push_back(make_pair(0, 0));
	REP(i, m) {
		int a;
		cin >> a;
		seconder.push_back(make_pair(a, 0));
	}
	REP(i, m) {
		int a;
		cin >> a;
		seconder[i + 1].second = a;
	}
	long long minimum = LONG_INF;
	for (int i = 0;i < n+1;++i) {
		int left_mana = s - firster[i].second;
		if (left_mana < 0) goto fail;
		int top = m;
		int bot = 0;
		int left_posion = k;
		while (top - bot > 1) {
			int mid = top + bot;
			mid /= 2;
			if (seconder[mid].second > left_mana) {
				top = mid;
			}
			else {
				bot = mid;
			}
		}
		if (seconder[top].second <= left_mana) {
			left_posion -= seconder[top].first;
		}
		else {
			left_posion -= seconder[bot].first;
		}
		minimum = min(minimum, firster[i].first * max((long long)0,left_posion));
		fail:;
	}
	cout << minimum << endl;
	return 0;
}