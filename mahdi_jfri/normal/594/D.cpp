#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 2e5 + 20;
const int maxa = 1e6 + 20;
const int mod = 1e9 + 7;

int a[maxn] , pm[maxn] , ans[maxn] , pos[maxa];
int prime[maxa] , l[maxn] , r[maxn] , res[maxa] , fen[maxn];

vector<int> lq[maxn];

ll pw(ll a , ll b)
{
	if(!b)
		return 1;
	ll x = pw(a , b / 2);
	x = (x * x) % mod;
	if(b & 1)
		x = (x * a) % mod;
	return x;
}

void change(int p , int val)
{
	for(p++; p < maxn; p += lb(p))
		fen[p] = 1LL * fen[p] * val % mod;
}

int get(int p)
{
	int res = 1;
	for(p++; p > 0; p -= lb(p))
		res = 1LL * res * fen[p] % mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 2; i < maxa; i++)
		if(!prime[i])
			for(int j = i; j < maxa; j += i)
				prime[j] = i;
	for(int i = 1; i < maxa; i++)
		res[i] = 1LL * (i - 1) * pw(i , mod - 2) % mod;
	fill(fen , fen + maxn , 1);
	fill(pm , pm + maxn , 1);
	fill(pos , pos + maxa , maxn);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		pm[i + 1] = 1LL * pm[i] * a[i] % mod;
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
		lq[r[i]].pb(i);
		ans[i] = 1LL * pm[r[i] + 1] * pw(pm[l[i]] , mod - 2) % mod;
	}

	for(int i = 0; i < n; i++)
	{
		int z = a[i];
		while(z > 1)
		{
			int tmp = prime[z];
			while(z % tmp == 0)
				z /= tmp;
			change(pos[tmp] , pw(res[tmp] , mod - 2));
			pos[tmp] = i;
			change(pos[tmp] , res[tmp]);
		}
		for(auto x : lq[i])
			ans[x] = 1LL * ans[x] * (1LL * get(maxn - 2) * pw(get(l[x] - 1) , mod - 2) % mod) % mod;
	}
	
	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
}