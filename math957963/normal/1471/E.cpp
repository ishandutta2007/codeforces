#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int n, k;
	int x, y;
	int cnt = -1;
	cin >> n >> k;
	if (n <= 30) {
		bool v;
		rep(i, n) {
			v = true;
			rep(j, n) {
				cout << "? " << i + 1 << endl;
				cout.flush();
				cin >> y;
				if (y != k)v = false;
			}
			if (v) {
				x = i;
				if (x == 0)x = n;
				rep(j, 3) {
					cout << "? " << x << endl;
					cout.flush();
					cin >> y;
					if (y > k)v = false;
				}
				x = i + 2;
				if (x == n + 1)x = 1;
				rep(j, 3) {
					cout << "? " << x << endl;
					cout.flush();
					cin >> y;
					if (y < k)v = false;
				}
				if (v) {
					cout << "! " << i + 1 << endl;
					cout.flush();
					return 0;
				}
			}
		}
	}
	int kk = 1;
	while ((2 * kk*kk) < n)kk++;
	rep(i, kk) {
		cout << "? " << 1 << endl;
		cout.flush();
		cnt++;
		cin >> y;
	}
	kk = (2 * kk);
	x = 0;
	while (true) {
		cout << "? " << x + 1 << endl;
		cnt++;
		cout.flush();
		cin >> y;
		if (y != k)break;
		x = (x + 1) % n;
		cout << "? " << x + 1 << endl;
		cnt++;
		cout.flush();
		cin >> y;
		if (y != k)break;
		x = (x + kk) % n;
	}
	if (y < k) {
		x -= (kk + 4);
		x = (x + n) % n;
		while (true) {
			cout << "? " << x + 1 << endl;
			cnt++;
			cout.flush();
			cin >> y;
			if (y != k)break;
			x = (x + 1) % n;
		}
		x = (x + n - 2) % n;
		cout << "? " << x + 1 << endl;
		cout.flush();
		cin >> y;
		x = (x + 2) % n;
		if (y != k)x = (x + n - 1 + cnt) % n;
		else x = (x + cnt) % n;
	}
	else {
		x += (kk + 4);
		x = (x + n) % n;
		while (true) {
			cout << "? " << x + 1 << endl;
			cnt++;
			cout.flush();
			cin >> y;
			if (y != k)break;
			x = (x + n - 1) % n;
		}
		x = (x + 2) % n;
		cout << "? " << x + 1 << endl;
		cout.flush();
		cin >> y;
		x = (x + n - 2) % n;
		if (y != k)x = (x + 1 - cnt + n) % n;
		else x = (x - cnt + n) % n;
	}
	cout << "! " << x + 1 << endl;
	cout.flush();
	return 0;
}