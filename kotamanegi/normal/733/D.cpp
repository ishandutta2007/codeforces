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
map<pair<int, int>, pair<int, int>> wow;
int main() {
	long long n;
	cin >> n;
	long long max = -1;
	pair<int, int> index = {-1,-1};
	REP(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<tuple<int, int, int>> ask;
		ask.push_back(make_tuple(a, b, c));
		if (!(a == b&&b == c)) {
			if (b != c) {
				ask.push_back(make_tuple(a, c, b));
			}
			if (b != a) {
				ask.push_back(make_tuple(b, a, c));
			}
			if (a != c && b != c&&a != b) {
				ask.push_back(make_tuple(b, c, a));
				ask.push_back(make_tuple(c, a, b));
			}
			if (a != c) {
				ask.push_back(make_tuple(c, b, a));
			}
		}

		REP(q,ask.size()) {
			pair<int, int> gogo = make_pair(get<0>(ask[q]),get<1>(ask[q]));	
			if (wow[gogo].first != 0) {
				if (min(gogo.first, min(gogo.second, get<2>(ask[q]) + wow[gogo].first)) > max) {
					max = min(gogo.first, min(gogo.second, get<2>(ask[q]) + wow[gogo].first));
					index = make_pair(wow[gogo].second, i + 1);
				}
				if (wow[gogo].first < get<2>(ask[q])) {
					wow[gogo].first = get<2>(ask[q]);
					wow[gogo].second = i + 1;
				}
			}
			else {
				wow[gogo].first = get<2>(ask[q]);
				wow[gogo].second = i + 1;
				if (min(gogo.first, min(gogo.second, get<2>(ask[q]))) > max) {
					max = min(gogo.first, min(gogo.second, get<2>(ask[q])));
					index = make_pair(i + 1, -1);
				}
			}
		}
	}
	if (index.second == -1) {
		cout << "1" << endl;
		cout << index.first << endl;
		return 0;
	}
	else {
		cout << "2" << endl;
		cout << index.first << " " << index.second << endl;
		return 0;
	}
	return 0;
}