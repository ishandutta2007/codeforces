#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int modexp(int v, int p, int m){
	if (p == 0) return 1;
	int ans = modexp(1LL * v * v % m, p / 2, m);
	if (p & 1) ans = 1LL * ans * v % m;
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	if (n == 1){
		cout << "YES" << endl;
		cout << 1 << endl;
	}
	else if (n == 4){
		cout << "YES" << endl;
		cout << "1 3 2 4" << endl;
	}
	else{
		bool prime = true;
		for (int i = 2; i * i <= n && prime; ++i)
			if (n % i == 0) prime = false;
		if (!prime)
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			cout << 1 << endl;
			for (int i = 2; i < n; ++i)
				cout << 1LL * i * modexp(i - 1, n - 2, n) % n << endl;
			cout << n << endl;
		}
	}


	return 0;
}