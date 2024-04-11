#include <bits/stdc++.h>
#define int long long
using namespace std;

int k,n,s,p;
signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> k >> n >> s >> p;
	int res = (n + s - 1) / s;
	res *= k;
	res = (res + p - 1) / p;
	cout << res;
}