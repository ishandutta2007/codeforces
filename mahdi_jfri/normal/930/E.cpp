#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 4e5 + 20;
const int mod = 1e9 + 7;

int l[maxn] , r[maxn];
vector<int> rq[2][maxn] , tmp;

int res[2][maxn] , last[2] , fen[2][maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

inline void update(int p , int id , int val)
{
	mkay(res[id][p] += val);

	for(p += 5; p < maxn; p += lb(p))
		mkay(fen[id][p] += val);
}

inline int get(int p , int id)
{
	int res = 0;
	for(p += 5; p > 0; p -= lb(p))
		mkay(res += fen[id][p]);

	return res;
}

int pw(int b)
{
	if(!b)
		return 1;

	int x = pw(b / 2);
	
	x = 1LL * x * x % mod;
	if(b&1)
		x = 2LL * x % mod;

	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k , n , m;
	cin >> k >> n >> m;

	tmp.pb(0);
	tmp.pb(1);
	tmp.pb(k);
	for(int i = 0; i < n + m; i++)
	{
		cin >> l[i] >> r[i];

		tmp.pb(l[i]);
		tmp.pb(r[i]);
	}

	sort(tmp.begin() , tmp.end());
	tmp.resize(unique(tmp.begin() , tmp.end()) - tmp.begin());

	for(int i = 0; i < n + m; i++)
	{
		l[i] = lower_bound(tmp.begin() , tmp.end() , l[i]) - tmp.begin();
		r[i] = lower_bound(tmp.begin() , tmp.end() , r[i]) - tmp.begin();

		rq[i < n][r[i]].pb(l[i]);
	}

	n = (int)tmp.size();

	update(0 , 0 , 1);
	update(0 , 1 , 1);

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			int shit = 0;
			for(auto ind : rq[j][i])
				shit = max(shit , ind);

			while(last[!j] < shit)
			{
				update(last[!j] , !j , -res[!j][last[!j]]);
				last[!j]++;
			}
		}

		if(i + 1 < n)
		{
			for(int x = 0; x < 2; x++)
			{
				int upd = 0;

				mkay(upd += 1LL * get(i - 1 , x) * (pw(tmp[i + 1] - tmp[i] - 1) - 1 + mod) % mod);
				mkay(upd += 1LL * get(i - 1 , !x) * pw(tmp[i + 1] - tmp[i] - 1) % mod);

				update(i , x , upd);
			}
		}
	}

	int res = 0;

	for(int j = 0; j < 2; j++)
		mkay(res += get(maxn - 10 , j));

	cout << res << endl;
}