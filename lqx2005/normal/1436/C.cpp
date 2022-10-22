#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
int n, x, pos;
int A(int n, int m)
{
	if(n < m) return 0;
	int ans = 1;
	for(int i = n; i >= n - m + 1; i--) ans = 1ll * ans * i % mod;
	return ans;
}
int main()
{
	scanf("%d%d%d", &n, &x, &pos);
	int le = 0, ri = 0;
	int l = 0, r = n;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(mid <= pos) le++, l = mid + 1;
		else ri++, r = mid;
	}
	int ans = 1;
	if(le > x) return printf("0\n"), 0;
	if(ri > n - x) return printf("0\n"), 0;
	ans = 1ll * ans * A(x - 1, le - 1) % mod;
	ans = 1ll * ans * A(n - x, ri) % mod;
	ans = 1ll * ans * A(n - le - ri, n - le - ri) % mod;
	printf("%d\n", ans);
	return 0;
}