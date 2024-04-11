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

int n;
vec< int > a;
vec< ll > sum;

ld ans_value = 0.0;
int ans_pos = 0, ans_len = 0;

ld f(int pos, int len) {
	if(len == 0) return 0.0;
	
	ll t_sum = sum[pos] - (pos - len > 0?sum[pos - len - 1] : 0) + 
		sum[n - 1] - (n - len > 0?sum[n - len - 1] : 0);

	ll cnt = 2 * len + 1;

	return (ld)t_sum / (ld)cnt - a[pos];
}

void upd(int pos, int len) {
	ld tmp = f(pos, len);
	if(tmp > ans_value) {
		ans_value = tmp;
		ans_pos = pos;
		ans_len = len;
	}
}

void print(int pos, int len) {
	cout << len * 2 + 1 << '\n';
	for(int i = pos;i >= pos - len;i--) {
		cout << a[i] << ' ';
	}
	for(int i = n - len;i < n;i++) cout << a[i] << ' ';
	cout << '\n';
}

bool solve() {
	
	scanf("%d", &n);

	a.resize(n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	
	sort(ALL(a));

	sum.resize(n);
	sum[0] = a[0];
	for(int i = 1;i < n;i++) {
		sum[i] = sum[i - 1] + a[i];
	}

	for(int i = 0;i < n;i++) {
		int l = 0, r = min(i, n - i - 1);
		int m1, m2;
		while(r - l > 2) {
			m1 = l + (r - l) / 3;
			m2 = r - (r - l) / 3;
			if(f(i, m1) < f(i, m2)) l = m1;
			else r = m2;
		}
		for(int j = l;j <= r;j++) upd(i, j);
	}

	print(ans_pos, ans_len);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}