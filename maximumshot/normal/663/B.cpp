#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

string toString(int val) {
	string ans;
	while(val) ans.push_back(val % 10 + '0'), val /= 10;
	reverse(ALL(ans));
	return ans;
}

int get(string s) {
	int now = 1989, cnt = 1, ten = 10;
	while(cnt < (int)s.size()) {
		now += ten;
		cnt++;
		ten *= 10;
	}
	string L = toString(now);
	int sz = (int)L.size(), val = 0;
	for(auto i : s) val = val * 10 + i - '0';
	int st = 0;
	for(int i = sz - cnt;i < sz;i++) st = st * 10 + L[i] - '0';
	int x = val - st;
	x = (x % ten + ten) % ten;
	return now + x;
}

bool solve() {

	int n;
	cin >> n;

	string s;
	
	for(int i = 0;i < n;i++) {
		cin >> s;
		s = s.substr(4);
		cout << get(s) << '\n';
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}