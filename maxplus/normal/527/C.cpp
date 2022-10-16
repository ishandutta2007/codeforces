#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <bitset>
#include <time.h>

using namespace std;

int main() {
	cin.tie(0), ios_base::sync_with_stdio(false);
	long long w, h, N;
	cin >> w >> h >> N;
	set<long long> height, width, ansH, ansW;
	map<long long, long long> t1, t2;
	height.insert(0);
	height.insert(h);
	width.insert(0);
	width.insert(w);
	ansH.insert(h);
	ansW.insert(w);
	t1[h]++, t2[w]++;
	for (int i = 0; i < N; i++) {
		char c;
		long long pos;
		cin >> c >> pos;
		if (c == 'H') {
			auto it = height.upper_bound(pos);
			long long l, r = *it;
			it--;
			l = *it;
			t1[r - l]--;
			if (!t1[r - l])
				ansH.erase(r - l);
			t1[r - pos]++, t1[pos - l]++;
			ansH.insert(r - pos), ansH.insert(pos - l);
			height.insert(pos);
		}
		else {
			auto it = width.upper_bound(pos);
			long long l, r = *it;
			it--;
			l = *it;
			t2[r - l]--;
			if (!t2[r - l])
				ansW.erase(r - l);
			t2[r - pos]++, t2[pos - l]++;
			ansW.insert(r - pos), ansW.insert(pos - l);
			width.insert(pos);
		}
		auto it = ansH.end(), it1 = ansW.end();
		it--, it1--;
		cout << (*it) * (*it1) << endl;
	}
	return 0;
}