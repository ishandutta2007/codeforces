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

char f(char x, char y) {
	for(char i = 'a';i <= 'c';i++) {
		if(x != i && y != i) return i;
	}
}

bool solve() {
		
	int n, t;
	cin >> n >> t;

	t = n - t;

	string a, b;
	cin >> a >> b;

	int cnt = 0;

	for(int i = 0;i < n;i++) cnt += (a[i] == b[i]);

	if(cnt >= t) {
		for(int i = 0;i < n;i++) {
			if(t > 0 && a[i] == b[i]) cout << a[i], t--;
			else cout << f(a[i], b[i]);
		}
		cout << '\n';
		return true;
	}

	int ost = t - cnt;

	if(cnt + ost * 2 <= n) {
		int q1, q2;
		q1 = q2 = ost;
		for(int i = 0;i < n;i++) {
			if(a[i] == b[i]) cout << a[i];
			else {
				if(q1 > 0) cout << a[i], q1--;
				else if(q2 > 0) cout << b[i], q2--;
				else cout << f(a[i], b[i]);
			}
		}
		cout << '\n';
	}else {
		cout << -1 << '\n';
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}