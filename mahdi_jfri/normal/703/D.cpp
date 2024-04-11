#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
const int maxn = 1e6 + 20;

vector<int> ql[maxn];

int a[maxn] , px[maxn] , b[maxn] , now , l[maxn] , r[maxn] , fen[maxn] , ans[maxn];
int last[maxn] , nex[maxn];

void update(int pos , int val)
{
	for(pos++; pos < maxn; pos += lb(pos))
		fen[pos] ^= val;
}

int get(int pos)
{
	int res = 0;
	for(pos++; pos > 0; pos -= lb(pos))
		res ^= fen[pos];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill(last , last + maxn , -1);
	fill(nex , nex + maxn , -1);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
		px[i] = a[i];
		if(i)
			px[i] ^= px[i - 1];
	}
	sort(b , b + n);
	int m = unique(b , b + n) - b;
	for(int i = 0; i < n; i++)
	{
		ll k = lower_bound(b , b + m , a[i]) - b;
		if(last[k] != -1)
			nex[last[k]] = i;
		else
			update(i , a[i]);
		last[k] = i;
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		l[i]--;
		r[i]--;
		ql[l[i]].pb(i);
		ans[i] = px[r[i]] ^ px[l[i]] ^ a[l[i]];
	}
	for(int i = 0; i < n; i++)
	{
		for(auto e : ql[i])
			ans[e] ^= get(r[e]) ^ get(i - 1);
		update(i , a[i]);
		if(nex[i] != -1)
			update(nex[i] , a[i]);
	}
	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}