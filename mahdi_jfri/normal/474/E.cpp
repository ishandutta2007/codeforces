#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll mx[4 * maxn] , a[maxn] , pos[maxn] , dp[maxn];
pair<ll , ll> h[maxn];
void update(ll p , ll value , ll s , ll e , ll v)
{
	if(e == s)
	{
		mx[v] = value;
		return;
	}
	ll mid = (s + e) / 2;
	if(p <= mid)
		update(p , value , s , mid , 2 * v);
	else
		update(p , value , mid + 1 , e , 2 * v + 1);
	if(mx[2 * v] > mx[2 * v + 1])
		mx[v] = mx[2 * v];
	else
		mx[v] = mx[2 * v + 1];
}
int get(ll l , ll r , ll s , ll e , ll v)
{
	if(r < s || l > e)
		return 0;
	if(s >= l && e <= r)
		return mx[v];
	ll mid = (s + e) / 2;
	return max(get(l , r , s , mid , 2 * v) , get(l , r , mid + 1 , e , 2 * v + 1));
}
int main()
{
	ll n , d;
	cin >> n >> d;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		h[i].first = a[i];
		h[i].second = i;
	}
	sort(h , h + n);
	for(int i = 0; i < n; i++)
		pos[h[i].second] = i;
	for(int i = 0; i < n; i++)
		update(i , -1 , 0 , n - 1 , 1);
	ll mx = 0;
	for(int i = 0; i < n; i++)
	{
		pair<ll , ll> x;
		x.first = a[i] - d;
		x.second = maxn;
		int r = lower_bound(h , h + n , x)-h-1;
		x.first = d + a[i];
		x.second = -1;
		int l = lower_bound(h , h + n , x)-h;
		int upd = max(get(0 , r , 0 , n - 1 , 1) , get(l , n - 1 , 0 , n - 1 , 1));
		if(!i)
			upd = 0;
		dp[i] = upd + 1;
		update(pos[i] , dp[i] , 0 , n - 1 , 1);
		if(dp[i] > dp[mx])
			mx = i;
	}
	cout << dp[mx] << endl;
	vector<int> ans;
	ans.pb(mx);
	for(int i = mx; i >= 0; i--)
	{
		if(dp[i] == dp[mx] - 1 && abs(a[i] - a[mx]) >= d)
		{
			mx = i;
			ans.pb(i);
		}
	}
	reverse(ans.begin() , ans.end());
	for(auto x : ans)
		cout << x + 1 << " ";
}