#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int a[maxn], b[maxn];
int c[maxn], d[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, L;
	cin >> n >> L;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	for (int i = 1; i < n; i++) c[i] = a[i] - a[i - 1];
	c[0] = L - (a[n - 1] - a[0]);

	bool corr = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int kl = (i + j) % n;
			int kr = (i + j + 1) % n;
				d[j] = b[kr] - b[kl];
			if (kl == n - 1 && kr == 0) d[j] += L;
			// cerr << c[j] << "/" << d[j] << " ";
		}
		// cerr << endl;
		bool eq = true;
		for (int j = 0; j < n; j++) {
			eq &= c[j] == d[j];
		}
		if (eq) corr = true;
	}

	cout << (corr ? "YES" : "NO") << endl;
	return 0;
}