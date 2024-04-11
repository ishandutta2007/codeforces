#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 200100
#define MOD 1000000007 //998244353
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	char a[N];
	int t, n, x, s;
	rep(i, N)a[i] = 0;
	cin >> t;
	rep(tt, t) {
		cin >> a;
		n = strlen(a);
		x = 0;
		s = 0;
		rep3(i, n - 1, 0) {
			if (a[i] == 'A')x++;
			else x--;
			s = max(s, x);
		}
		if ((n + s) % 2 == 1)s++;
		cout << s << endl;
		rep(i, n + 1)a[i] = 0;
	}
	return 0;
}