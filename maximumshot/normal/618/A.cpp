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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n;
	cin >> n;

	vec< int > a;

	for(int i = 0;i < n;i++) {
		a.push_back(1);
		while((int)a.size() > 1) {
			int sz = (int)a.size();
			if(a[sz - 2] == a[sz - 1]) {
				int x = a[sz - 1];
				a.pop_back();
				a.pop_back();
				a.push_back(x + 1);
			}else break;
		}
	}

	for(auto i : a) cout << i << ' ';
	cout << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}