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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	vec< pii > a(3);
	for(int i = 0;i < 3;i++) cin >> a[i].first >> a[i].second;

	if(a[0].first == a[1].first && a[1].first == a[2].first || 
		a[0].second == a[1].second && a[1].second == a[2].second) {
		cout << 1 << '\n';
		return true;
	}

	for(int i = 0;i < 3;i++) {
		for(int j = 0;j < 3;j++) {
			if(i == j) continue;
			int k = 3 - i - j;
			if(a[i].first == a[j].first && (a[k].second <= min(a[i].second, a[j].second) || a[k].second >= max(a[i].second, a[j].second) ) ) {
				cout << 2 << '\n';
				return true;
			}
			swap(a[i].first, a[i].second);
			swap(a[j].first, a[j].second);
			swap(a[k].first, a[k].second);
			if(a[i].first == a[j].first && (a[k].second <= min(a[i].second, a[j].second) || a[k].second >= max(a[i].second, a[j].second) ) ) {
				cout << 2 << '\n';
				return true;
			}
			swap(a[i].first, a[i].second);
			swap(a[j].first, a[j].second);
			swap(a[k].first, a[k].second);		
		}
	}

	cout << 3 << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}