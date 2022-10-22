#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef double db;
typedef long long i64;
const int N = 1e6 + 10, LG = 21;
int n, a[N];
int mn[1 << LG];
par mx[1 << LG];

void chkmin(int &x, int y) {
	if(x > y) x = y;
}

void chkmax(par &a, int y) {
	if(a.x < y) a.y = a.x, a.x = y;
	else if(a.y < y) a.y = y;
	return;
}

void init() {
	for(int i = 0; i < 1 << LG; i++) {
		mn[i] = n + 1, mx[i] = mp(0, 0);
	}
	for(int i = 1; i <= n; i++) {
		chkmin(mn[a[i]], i);
		chkmax(mx[a[i]], i);
	}
	for(int i = 2; i <= 1 << LG; i <<= 1) {
		for(int j = 0; j < 1 << LG; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				chkmin(mn[j + k], mn[j + k + (i >> 1)]);
				chkmax(mx[j + k], mx[j + k + (i >> 1)].x);
				chkmax(mx[j + k], mx[j + k + (i >> 1)].y);
			}
		}
	}
	return;
} 


int check(int mask) {
	for(int i = 0; i < 1 << LG; i++) {
		if((mask & i) != i) continue;
		int R = mx[i].y, L = mn[mask ^ i];
		if(L < R) {
			return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init();
	int ans = 0;
	for(int i = LG - 1; i >= 0; i--) {
		ans = ans ^ 1 << i;
		if(!check(ans)) ans = ans ^ 1 << i;
	}
	cout << ans << endl;
    return 0;
}