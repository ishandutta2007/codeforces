#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	int p = 0;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if (v[i] < v[p])
			p = i;
	}

	if (p == 0){
		p = n - 1;
		while (p >= 0 && v[p] == v[0]) p--;
		p = (p + 1) % n;
	}

	bool ok = true;
	for (int i = 1; i < n && ok; ++i){
		if (v[(p + i) % n] < v[(p + i - 1 + n) % n])
			ok = false;
	}

	if (!ok)
		cout << -1 << endl;
	else{
		if (!p) cout << p << endl;
		else cout << n - p << endl;
	}

	return 0;
}