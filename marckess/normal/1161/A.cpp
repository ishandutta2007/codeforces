#include <bits/stdc++.h>

using namespace std;

const int MX = 100005;
int n, k, x[MX], f[MX], l[MX], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> x[i];
		if (!f[x[i]]) f[x[i]] = i;
		l[x[i]] = i;
	}

	l[0] = k + 1;
	l[n+1] = k + 1;
	
	for (int i = 1; i <= n; i++) {
		if (!f[i]) res += 3 - int(i == 1) - int(i == n);
		else {
			if (f[i] > l[i+1]) res++;
			if (f[i] > l[i-1]) res++;
		}
	}

	cout << res << endl;

	return 0;
}