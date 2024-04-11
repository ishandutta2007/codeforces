#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;
const int oo = 0x3f3f3f3f;

int v[maxn];
int a[maxn];

int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	int l = 0;

	for (int i = 0; i < n; ++i){
		l++;
		a[i] = min(l, v[i]);
		l = a[i];
	}

	l = 0;
	for (int i = n - 1; i >= 0; --i){
		l++;
		int val = min(l, v[i]);
		a[i] = min(a[i], val);
		l = val;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, a[i]);

	cout << ans << endl;
}