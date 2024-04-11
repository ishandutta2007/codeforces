#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef pair<ll , ll> pll;
const int maxn = 1e5 + 20;

ll pos[maxn] , r[maxn] , a[maxn] , L[maxn] , R[maxn] , ans[maxn];

vector<ll> pm[maxn * 4];
vector<pll> seg[maxn * 4];

pair<ll , ll> x[maxn];

pll make_pair(ll a , ll b)
{
	return {a , b};
}

void build(int s , int e , int v)
{
	pm[v].clear();
	seg[v].clear();
	if(e - s < 2)
	{
		seg[v].pb({r[x[s].second] , s});
		pm[v].pb(ans[s]);
		pm[v].pb(-1);
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	for(auto k : seg[2 * v])
		seg[v].pb(k);
	for(auto k : seg[2 * v + 1])
		seg[v].pb(k);
	sort(seg[v].begin() , seg[v].end());

	pm[v].pb(-1);
	for(int i = ((int)seg[v].size()) - 1; i >= 0; i--)
		pm[v].pb(max(ans[seg[v][i].second] , pm[v].back()));

	reverse(pm[v].begin() , pm[v].end());
}

ll get_t(int l , int r , ll val , int s , int e , int v)
{
	if(l <= s && e <= r)
		return upper_bound(seg[v].begin() , seg[v].end() , make_pair(val , (ll) maxn)) - seg[v].begin();
	if(r <= s || e <= l)
		return 0;
	int m = (s + e) / 2;
	return get_t(l , r , val , s , m , 2 * v) + get_t(l , r , val , m , e , 2 * v + 1);
}

ll get(int l , int r , ll val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		int ind = lower_bound(seg[v].begin() , seg[v].end() , make_pair(val , -1LL)) - seg[v].begin();
		return pm[v][ind];
	}
	if(r <= s || e <= l)
		return -1;
	int m = (s + e) / 2;
	return max(get(l , r , val , s , m , 2 * v) , get(l , r , val , m , e , 2 * v + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> r[i];
	for(int i = 0; i < n; i++)
		cin >> a[i] , x[i] = {a[i] , i};
	sort(x , x + n);
	for(int i = 0; i < n; i++)
		pos[x[i].second] = i;
	for(int i = 0; i < n; i++)
	{
		R[i] = upper_bound(x , x + n , make_pair(x[i].first + (ll)k , (ll)maxn)) - x;
		L[i] = lower_bound(x , x + n , make_pair(x[i].first - k , -1LL)) - x;
	}
	build(0 , n , 1);
	for(int i = 0; i < n; i++)
		ans[i] = get_t(L[i] , R[i] , r[x[i].second] , 0 , n , 1);
	build(0 , n , 1);
	int q;
	cin >> q;
	while(q--)
	{
		int x1 , y;
		cin >> x1 >> y;
		x1--;
		y--;
		x1 = pos[x1];
		y = pos[y];
		if(x1 > y)
			swap(x1 , y);
		int tmpL , tmpR , mx = max(r[x[x1].second] , r[x[y].second]);
		tmpR = R[x1] , tmpL = L[y];
		if(tmpR <= tmpL)
		{
			cout << -1 << endl;
			continue;
		}
		cout << get(tmpL , tmpR , mx , 0 , n , 1) << endl;
	}
}