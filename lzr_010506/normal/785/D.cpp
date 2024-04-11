#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
struct Node
{
	int l, r, ans;
};
char ch[200010];
int r[200010];
ll ans, jc[200010], ni[200010];

ll qpow(ll a, int b)
{
	if(b == 1) return a;
	ll pp = qpow(a, b / 2) % mod;
	if(b % 2 == 1) return (pp * pp) % mod * a % mod;
	else return (pp * pp) % mod;
}

ll C(int a, int b)
{
	ll now = jc[a];
	now *= ni[b];
	now %= mod;
	now *= ni[a - b];
	now %= mod;
	return now;
}

Node fen(int l, int r)
{
	Node now;
	now.l = now.r = now.ans = 0;
	if(l == r)
	{
		if(ch[l] == '(') now.l ++;
		else now.r ++;
		return now;
	}
	int mid = (l + r) >> 1;
	Node L = fen(l, mid);
	Node R = fen(mid + 1, r);
	now.l = L.l + R.l;
	now.r = L.r + R.r;
	now.ans += L.ans + R.ans;
	now.ans %= mod;
	for(int i = 1; i <= min(L.l, R.r); i ++)
		now.ans = (now.ans + C(L.l, i) * C(R.r, i)) % mod;
	//cout << l << " " << r << " " << now.l << " " << now.r << " " << now.ans << endl;
	return now;
}

int main()
{
	jc[0] = 1;
	ni[0] = 1;
	for(int i = 1; i <= 200000; i ++)
	{
		jc[i] = jc[i - 1] * i % mod;
		ni[i] = qpow(jc[i], mod - 2) % mod;
    }
	scanf("%s", ch + 1);
	int n = strlen(ch + 1);
	for(int i = n; i >= 1; i --)
		r[i] = r[i + 1] + (ch[i] == ')');
	//for(int i = 1; i <= n; i ++)
	//	cout << r[i] << " ";
	int l = 0;
	for(int i = 1; i <= n; i ++)
		if(ch[i] == '(')
		{
			l ++;
			/*ans += r[i];
			if(ans > mod) ans -= mod;
			if(l > r[i]) continue;
            int m;
			if(l <= r[i]) m = l;
			else m = r[i];
			for(int j = 1; j < m; j ++)
				ans = (ans + C(l - 1, j) * C(r[i], j + 1) % mod) % mod;
			*/
			ans = (ans + C(l + r[i] - 1, r[i] - 1)) % mod;
		}
	cout << ans;
	//Node ans = fen(1, n);
	//cout << ans.ans;
	//cout << C(2, 2);
	//cout << qpow(2, mod - 2);
	return 0;
}