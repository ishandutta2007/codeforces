#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define X first
#define Y second
#define pii pair<int, int>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
int b[N], c[N], a[N];
int f[N * 20];
int main()
{
	rep(i, 1, 1000) a[i] = 0x3f3f3f3f;
	a[1] = 0;
	rep(i, 1, 1000)
		rep(x, 1, i)
			a[i + i / x] = min(a[i + i / x], a[i] + 1); 
	//rep(i, 1, 10) cout << i << ":" << a[i] << "\n";
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		int n, k;
		cin >> n >> k;
		rep(i, 1, n) cin >> b[i], b[i] = a[b[i]];
		rep(i, 1, n) cin >> c[i];
		//rep(i, 1, n) cout << b[i] << " ";
		k = min(20 * n, k);
		rep(i, 1, k) f[i] = 0;
		f[0] = 0;
		rep(i, 1, n)
			rrep(j, k, b[i])
				f[j] = max(f[j], f[j - b[i]] + c[i]);
		cout << f[k] << "\n";
	}
}