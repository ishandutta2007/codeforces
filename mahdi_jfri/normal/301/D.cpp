#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
typedef pair<ll , ll> pll;
const int maxn = 2e5 + 20;

vector<ll> lq[maxn] , rq[maxn];

int a[maxn] , pos[maxn] , l[maxn] , r[maxn] , fen[maxn] , ans[maxn];

void add(int pos , int val)
{
	for(; pos < maxn; pos += lb(pos))
		fen[pos] += val;
}

int get(int pos)
{
	int res = 0;
	for(; pos > 0; pos -= lb(pos))
		res += fen[pos];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i];
		lq[l[i]].pb(i);
		rq[r[i]].pb(i);
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j += i)
			add(pos[j] , 1);
	for(int i = 1; i <= n; i++)
	{
		for(auto e : lq[i])
			ans[e] = get(r[e]) - get(i - 1);
		for(int j = a[i]; j <= n; j += a[i])
			add(pos[j] , -1);
		for(auto e : rq[i])
			ans[e] -= get(i) - get(l[e] - 1);
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
}