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
	iostream::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	int tmp = 0;
	vector<pair<int,int>> wow;
	int ttt = 0;
	for (int i = 0;i < s.length();++i) {
		if (s[i] == '0') {
			tmp++;
		}
		else {
			if (tmp >= b) {
				wow.push_back(make_pair(tmp,i-tmp-1));
			}
			ttt += tmp / b;
			tmp = 0;
		}
	}
	if (tmp >= b) {
		ttt += tmp / b;
		wow.push_back(make_pair(tmp, s.length()-tmp-1));
	}
	ttt -= a;
	vector<int> gogo;
	for (int i = 0;i < wow.size();++i) {
		for (int q = b;q <= wow[i].first;q += b) {
			if (ttt == -1) goto out;
			ttt--;
			gogo.push_back(wow[i].second + q+1);
			if (ttt == -1) goto out;
		}
	}
out:;
	cout << gogo.size() << endl;
	REP(i, gogo.size()) {
		cout << gogo[i] << " ";
	}
	cout << endl;
	return 0;
}