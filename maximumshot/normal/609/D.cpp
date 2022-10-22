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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m, k, s;
vec< int > a[2];
vec< pair< ll, int> > t[2];

bool check(int c) {
	int dollar = a[0][c - 1];
	int funt   = a[1][c - 1];
	for(int i = 0;i <= k;i++) {
		int j = k - i;
		if(i > (int)t[0].size() || j > (int)t[1].size()) continue;
		ll tmp = 1ll * dollar * (i?t[0][i - 1].first : 0) + 
			1ll * funt * (j?t[1][j - 1].first : 0);
		if(tmp <= s) return 1;
	}
	return 0;
}

void print(int c) {
	cout << c << '\n';
	int dollar = a[0][c - 1];
	int funt   = a[1][c - 1];
	int day1 = -1, day2 = -1;
	for(int i = 0;i < c;i++) {
		if(day1 == -1 && dollar == a[0][i]) day1 = i;
		if(day2 == -1 && funt == a[1][i]) day2 = i;
	}
	for(int i = 0;i <= k;i++) {
		int j = k - i;
		if(i > (int)t[0].size() || j > (int)t[1].size()) continue;
		ll tmp = 1ll * dollar * (i?t[0][i - 1].first : 0) + 
			1ll * funt * (j?t[1][j - 1].first : 0);
		if(tmp <= s) {
			for(int q = 0;q < i;q++) {
				cout << t[0][q].second + 1 << " " << day1 + 1 << "\n";
			}
			for(int q = 0;q < j;q++) {
				cout << t[1][q].second + 1 << " " << day2 + 1 << "\n";
			}
			return;
		}
	}
}

bool solve() {
	
	cin >> n >> m >> k >> s;

	for(int j = 0;j < 2;j++) {
		a[j].resize(n);
		for(int i = 0;i < n;i++) { 
			cin >> a[j][i];
			if(i) a[j][i] = min(a[j][i], a[j][i - 1]);
		}
	}

	for(int ty, cost, i = 0;i < m;i++) {
		cin >> ty >> cost;
		ty--;
		t[ty].push_back(mp(cost, i));
	}

	for(int i = 0;i < 2;i++) { 
		sort(ALL(t[i]));
		for(int j = 1;j < (int)t[i].size();j++) {
			t[i][j].first += t[i][j - 1].first;
		}
	}
	
	int l, r, m;

	l = 1, r = n;

	while(r - l > 1) {
		m = (l + r) / 2;
		if(check(m)) r = m;
		else l = m + 1;
	}
	
	if(check(l)) print(l);
	else if(check(r)) print(r);
	else cout << -1 << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}