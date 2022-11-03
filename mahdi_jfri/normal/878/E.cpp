#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;

int pw[maxn] , a[maxn] , sum[maxn] , l[maxn] , r[maxn] , ans[maxn] , ps[maxn] , sz;

vector<int> query[maxn];

vector<pair<int , int> > block;

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int get(int l , int r)
{
	if(l > r)
		return 0;
	int res = (sum[l] - 1LL * sum[r + 1] * pw[r - l + 1]) % mod;
	ok(res);

	return res;
}

ll get1(int l , int r)
{
	ll s = 0;
	for(int i = r; i >= l; i--)
		s = s * 2 + a[i];
	return s;
}

int main()
{
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2 % mod;

	int n , q;
	scanf("%d%d", &n, &q);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		l[i]--;
		r[i]--;
		query[r[i]].pb(i);
	}

	for(int i = n - 1; i >= 0; i--)
		sum[i] = (1LL * sum[i + 1] * 2 + a[i]) % mod;
	
	for(int i = 0; i < n; i++)
	{
		if(a[i] <= 0)
		{
			block.pb({i , i});
			ok(ps[sz] = (sz? ps[sz - 1] : 0) + a[i]);
			sz++;
		}
		else
		{
			ll sum = a[i];
			bool f = 1;
			for(int j = (int)block.size() - 1; j >= 0; j--)
			{
				auto seg = block[j];
				block.pop_back();
				if(seg.second - seg.first + 1 >= 30)
					break;

				ll s = get1(seg.first , seg.second);
				sum *= pw[seg.second - seg.first + 1];
				sum += s;
				if(sum <= 0)
				{
					ok(ps[j] = (j? ps[j - 1] : 0) + get(seg.first , i));
					block.pb({seg.first , i});
					f = 0;
					break;
				}
				if(sum >= mod)
					break;
			}
			if(f)
			{
				block.clear();
				ps[0] = get(0 , i);
				block.pb({0 , i});
			}
		}

		sz = block.size();

		for(auto j : query[i])
		{
			int k = upper_bound(block.begin() , block.end() , make_pair(l[j] , maxn)) - block.begin();

			if(k < (int)block.size())
			{
				ans[j] = get(l[j] , block[k].first - 1);
				ok(ans[j] += 2LL * (ps[sz - 1] - (k? ps[k - 1] : 0)) % mod);
			}
			else
				ans[j] = get(l[j] , i);
		}
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

}