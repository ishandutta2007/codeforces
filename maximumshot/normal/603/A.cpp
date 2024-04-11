#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

string gen_string(int n) {
	string ans = "";
	for(int i = 0;i < n;i++) ans += char(rand() % 2 + '0');
	return ans;
}

int slow(string a) {
	string b;
	int ans = 0, n = (int)a.size();
	for(int l = 0;l < n;l++) {
		for(int r = l;r < n;r++) {
			b = a;
			for(int q = l;q <= r;q++) {
				b[q] = (b[q] == '1'?'0' : '1');
			}
			ans = max(ans, unique(ALL(b)) - b.begin());
		}
	}
	return ans;
}

int fast(string a) {
	int n = (int)a.size();
	int l = n, r = -1;

	for(int i = 0;i + 1 < n;i++) {
		if(a[i] == a[i + 1]) {
			l = min(l, i);
			r = max(r, i);
		}
	}

	if(l == r) {
		for(int i = i;i <= l;i++) {
			a[i] = (a[i] == '1'?'0' : '1');
		}
	}else if(l != n) {
		for(int i = l + 1;i <= r;i++) {
			a[i] = (a[i] == '1'?'0' : '1');
		}
	}

	return (unique(ALL(a)) - a.begin());
} 

bool solve() {

	int n;
	cin >> n;

	if(n == 1) {
		cout << 1 << '\n';
		return true;
	}

	string a;
	cin >> a;

	cout << fast(a) << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}