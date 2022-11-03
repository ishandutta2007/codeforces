#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 2e5 + 20;
const int mod = 998244353;
const int pw2 = 499122177;

set<pair<int , int> > st[maxn];

int n , AddLazy[maxn * 4] , MulLazy[maxn * 4] , sum[maxn * 4];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

inline void handle(int s , int e , int v , int ml , int val)
{
	MulLazy[v] = 1LL * MulLazy[v] * ml % mod;
	AddLazy[v] = 1LL * AddLazy[v] * ml % mod;
	sum[v] = 1LL * sum[v] * ml % mod;

	mkay(AddLazy[v] += val);
	mkay(sum[v] += 1LL * (e - s) * val % mod);

	return;
}

inline void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		int m = (s + e) / 2;

		handle(s , m , 2 * v , MulLazy[v] , AddLazy[v]);
		handle(m , e , 2 * v + 1 , MulLazy[v] , AddLazy[v]);
	}

	MulLazy[v] = 1;
	AddLazy[v] = 0;
}

inline void mul(int l , int r , int val , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
	{
		handle(s , e , v , val , 0);
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;

	mul(l , r , val , s , m , 2 * v);
	mul(l , r , val , m , e , 2 * v + 1);

	mkay(sum[v] = sum[2 * v] + sum[2 * v + 1]);
}

inline void add(int l , int r , int val , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
	{
		handle(s , e , v , 1 , val);
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;

	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	mkay(sum[v] = sum[2 * v] + sum[2 * v + 1]);
}

int get(int l , int r , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
		return sum[v];
	if(r <= s || e <= l)
		return 0;

	shift(s , e , v);

	int m = (s + e) / 2 , ans = 0;

	mkay(ans = get(l , r , s , m , 2 * v) + get(l , r , m , e , 2 * v + 1));

	return ans;
}

void handle(int l , int r)
{
	add(l , r , 1);
	mul(l , r , pw2);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn * 4; i++)
		MulLazy[i] = 1;

	int q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		st[i].insert({0 , n});

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int l , r , k;
			cin >> l >> r >> k;
			l--;

			while(1)
			{
				auto it = st[k].lower_bound(make_pair(l , -100));

				if(it != st[k].end())
				{
					int L = it -> first , R = it -> second;

					if(l <= L && R <= r)
					{
						handle(L , R);
						st[k].erase(it);
						continue;
					}

					if(L < r)
					{
						st[k].erase(it);

						if(r < R)
							st[k].insert(make_pair(r , R));

						handle(L , r);
						continue;
					}

				}

				if(it != st[k].begin())
				{
					it--;
					int L = it -> first;
					int R = it -> second;

					if(l < R)
					{
						st[k].erase(it);
						if(L < l)
							st[k].insert(make_pair(L , l));
						if(r < R)
							st[k].insert(make_pair(r , R));
						handle(l , min(r , R));
						continue;
					}
				}

				break;
			}

			mul(l , r , 2);
		}

		if(type == 2)
		{
			int l , r;
			cin >> l >> r;
			l--;

			cout << get(l , r) << endl;
		}
	}

}