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
int main() {
	int n;
	vector<int> a;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	int k;
	cin >> k;
	vector<int> b;
	REP(i, k) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	vector<pair<int, int>> sections;
	int now_cnt = 0;
	int before = -1;
	int now_b = 0;
	int sector = 0;
	for (int i = 0;i < a.size();++i) {
		now_cnt += a[i];
		if (before == 0 && a[i] != a[i - 1]) before = 1;
		if (now_cnt == b[now_b]) {
			now_b++;
			if (before == 0||(now_b == k&&i != a.size()-1)) {
				cout << "NO" << endl;
				return 0;
			}
			sections.push_back(make_pair(sector, i));
			sector = i+1;
			before = -1;
			now_cnt = 0;
		}
		else {
			if (before == -1) before = 0;
		}
	}
	if (now_b == k) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
		return 0;
	}
	//output how to do
	int now_killed_cnt = 0;
	for (int i = 0;i < sections.size();++i) {
		int l = sections[i].first;
		int r = sections[i].second;
		int now_biggest = -1;
		int index = -1;
		for (int q = l;q <= r;++q) {
			if (a[q] > now_biggest) {
				now_biggest = a[q];
				index = q;
			}
		}
		int wow_cnt = 0;
		if (index == l&&r - l != 0&&a[index] == a[index+1]) {
			for (int q = index;q < a.size();++q) {
				if (a[q] != a[q + 1]) {
					index = q;
					goto good;
				}
			}
		good:;
			cout << (index - l+now_killed_cnt+1) << " R" << endl;
			wow_cnt = 1;
		}
		for (int q = index + 1;q > l + 1;q--) {
			cout << (q-l)+now_killed_cnt << " L" << endl;
		}
		now_killed_cnt++;
		for (int q = 0;q < r - index-wow_cnt;++q) {
			cout << now_killed_cnt << " R" << endl;
		}
	ok:;
	}
	return 0;
}