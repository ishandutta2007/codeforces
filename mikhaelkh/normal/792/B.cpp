#include <bits/stdc++.h>
using namespace std;


int const N = 101;

int a[N], n, k;

int nxt(int x) {
	for (x==n ? x=1 : ++x; a[x]; x==n ? x=1 : ++x);
	return x;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int cr = 1;
	int m = n;
	for (int i=0; i<k; ++i) {
		int a;
		cin >> a;
		a %= m;
		for (int i=0; i<a; ++i)
			cr=nxt(cr);
		cout << cr << ' ';
		::a[cr] = 1;
		cr = nxt(cr);
		--m;
	}
	return 0;
}