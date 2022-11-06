#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
const int P = 1e9 + 7;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define MOD 1000000007
ll p, k, ans[1000010];
int n;
int main()
{
	cin >> p >> k;
	while (p)
	{
		if(n & 1)
		{
			if(p % k == 0) ans[++ n] = 0; 
			else ans[++ n] = k - (p % k);
			p = (p - 1) / k + 1;
		}
		else ans[++ n] = p % k, p = p / k;
	}
	cout << n << endl;
	rep(i, 1, n)
		cout << ans[i] << " ";
	return 0;
}