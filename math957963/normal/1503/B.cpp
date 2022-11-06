#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
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
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int n, n2;
	int c, nx1, nx2, ny1, ny2;
	int k;
	cin >> n;
	nx1 = 0;
	ny1 = 0;
	nx2 = 0;
	ny2 = 1;
	n2 = n * n;
	rep(i, n2) {
		cin >> k;
		if (k == 1) {
			if (nx2 < n) {
				cout << 2 << " " << nx2 + 1 << " " << ny2 + 1 << endl;
				cout.flush();
				ny2 += 2;
				if (ny2 >= n) {
					nx2++;
					if (ny2 % 2 == 0)ny2 = 1;
					else ny2 = 0;
				}
			}
			else {
				cout << 3 << " " << nx1 + 1 << " " << ny1 + 1 << endl;
				cout.flush();
				ny1 += 2;
				if (ny1 >= n) {
					nx1++;
					if (ny1 % 2 == 0)ny1 = 1;
					else ny1 = 0;
				}
			}
		}
		else {
			if (nx1 < n) {
				cout << 1 << " " << nx1 + 1 << " " << ny1 + 1 << endl;
				cout.flush();
				ny1 += 2;
				if (ny1 >= n) {
					nx1++;
					if (ny1 % 2 == 0)ny1 = 1;
					else ny1 = 0;
				}
			}
			else {
				cout << 5 - k << " " << nx2 + 1 << " " << ny2 + 1 << endl;
				cout.flush();
				ny2 += 2;
				if (ny2 >= n) {
					nx2++;
					if (ny2 % 2 == 0)ny2 = 1;
					else ny2 = 0;
				}
			}
		}
	}


	return 0;
}