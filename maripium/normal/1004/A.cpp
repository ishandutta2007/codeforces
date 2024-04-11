#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i, l, r) for (int i = (l); i <= (r); ++i)
#define Ford(i, r, l) for (int i = (r); i >= (l); --i) 
using namespace std;

const int N = 105;

int n, d;
int a[N];
map<int,bool> hv;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> d;
	For(i, 1, n) cin >> a[i];
	hv[a[1] - d] = true, hv[a[n] + d] = true;
	For(i, 1, n) {
		if (i > 1 && a[i] - a[i - 1] >= 2 * d) hv[a[i] - d] = true;
		if (i < n && a[i + 1] - a[i] >= 2 * d) hv[a[i] + d] = true;
	}
	cout << hv.size();
}