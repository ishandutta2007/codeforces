#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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
	int t;
	int n;
	int a[N];
	int b[N];
	int k;
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> a[i];
		k = 0;
		rep(i, n - 1) {
			if (a[i] < a[i + 1])k += a[i + 1] - a[i];
		}
		if (k <= a[n - 1])cout << "YES" << endl;
		else cout << "NO" << endl;		
	}
	return 0;
}