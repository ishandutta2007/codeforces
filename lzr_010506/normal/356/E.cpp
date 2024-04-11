#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
const int P = 29;
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 10;
const int mod = 19260817;
const int Base = 29;
int n, suf[N][26], pre[N][26];
bool flag[22][N];
char s[N];
ll ans0, ans, gain[N][26], chg[N];
int power[N], h[N];
int query(int l, int r)
{
    int ret = h[r] - (ll)h[l - 1] * power[r - l + 1] % mod;
    return ret >= 0 ? ret : ret + mod;
}

bool is_same(int l1, int r1, int l2, int r2)
{
	if (l1 > r1 && l2 > r2) return 1;
	if (query(l1, r1) == query(l2, r2)) return 1;
	return 0;
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	power[0] = 1;
    rep(i, 1, n)
        power[i] = (ll)power[i - 1] * Base % mod,
    h[i] = ((ll)h[i - 1] * Base % mod + s[i]) % mod;
	rep(i, 1, n) flag[1][i] = 1, ans0 ++;
	rep(j, 0, 25) suf[0][j] = 0, pre[n + 1][j] = n + 1;
	rep(i, 1, n)
		rep(j, 0, 25)
			suf[i][j] = s[i - 1] == j + 'a' ? i - 1 : suf[i - 1][j];
	rrep(i, n, 1)
		rep(j, 0, 25)
			pre[i][j] = s[i + 1] == j + 'a' ? i + 1 : pre[i + 1][j];

	for (int k = 2; (1 << k) - 1 <= n; k ++)
		rep(i, 1, n)
		{
			int l = i - ((1 << k) - 1) / 2, r = i + ((1 << k) - 1) / 2;
			if (l < 1 || r > n) continue;
			ll w = (ll)(r - l + 1) * (r - l + 1);
			int lp = (l + i - 1) >> 1, rp = (i + 1 + r) >> 1;
			if (flag[k - 1][lp] && flag[k - 1][rp] && is_same(l, i - 1, i + 1, r))
			{
				if (suf[i][s[i] - 'a'] < l && pre[i][s[i] - 'a'] > r)
				{
					chg[l] -= w;
					chg[i] += w;
					chg[i + 1] -= w;
					chg[r + 1] += w;;
					flag[k][i] = 1, ans0 += w;
				}
				rep(j, 0, 25)
					if (j + 'a' != s[i])
					{
						if (!flag[k][i] && suf[i][j] < l && pre[i][j] > r) gain[i][j] += w;
						if (flag[k][i] && !(suf[i][j] < l && pre[i][j] > r)) gain[i][j] -= w;
					}
			}
			else if (flag[k - 1][lp] || flag[k - 1][rp])
			{
				int L = l, R = i - 1, p = 0;
				while (L <= R)
				{
					int mid = L + R >> 1;
					if (is_same(l, mid, i + 1, i + 1 + mid - l)) L = mid + 1;
					else p = mid, R = mid - 1;
				}
				if (is_same(p + 1, i - 1,r - (i - 1 - p - 1), r))
				{
					char c = s[p + (1 << k >> 1)];
					if (flag[k - 1][rp] && s[i] != c && pre[i][s[i] - 'a'] > r && (suf[i][s[i] - 'a'] < l || (suf[i][s[i] - 'a'] == p && suf[p][s[i] - 'a'] < l)))
						gain[p][c - 'a'] += w;
					c = s[p]; p += (1 << k >> 1);
					if (flag[k - 1][lp] && s[i] != c && suf[i][s[i] - 'a'] < l && (pre[i][s[i] - 'a'] > r || (pre[i][s[i] - 'a'] == p && pre[p][s[i] - 'a'] > r)))
						gain[p][c - 'a'] += w;
				}
			}
		}
	ll cur = 0;
	ans = ans0;
	rep(i, 1, n)
	{
		cur += chg[i];
		rep(j, 0, 25)
			if (j + 'a' != s[i])
				ans = max(ans, ans0 + cur + gain[i][j]);
	}
	cout << ans << endl;
	return 0;
}