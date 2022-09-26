#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, q;
int a[N];
int f1[N][N];
int f2[N][N];

int getval(int l,int r) {
	if (l == r) return a[l];
	int &res = f1[l][r];
	if (res != -1) return res;
	res = getval(l, r - 1) ^ getval(l + 1, r);
	return res;
}

int getmax(int l,int r) {
	if (l == r) return a[l];
	int &res = f2[l][r];
	if (res != -1) return res;
	res = getval(l, r);
	res = max(res, getmax(l + 1, r));
	res = max(res, getmax(l, r - 1));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) cin >> a[i];
	memset(f1, -1, sizeof f1);
	memset(f2, -1, sizeof f2);
	cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		cout << getmax(l, r) << '\n';
	}
}