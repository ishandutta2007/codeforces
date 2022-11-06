#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define pii pair<int, int>
#define mii map<int, int>
using namespace std;
int n[3], m[3], s[3];
ll N, M;
mii mp1, mp2;
vector<pii> vp;
vector<ll> v;
ll ans;
void dfs(int p, ll v)
{
	if(p == vp.size())
	{
		ans ++;
		return;
	}
	for(int i = 0; i <= vp[p].Y && v <= N; i++, v *= vp[p].X)
		dfs(p + 1, v);
}

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		scanf("%d%d%d%d%d%d%d%d%d",
		 n, n + 1, n + 2,
		 m, m + 1, m + 2,
		 s, s + 1, s + 2);
		N = (ll)n[0] * n[1] * n[2];
		M = (ll)m[0] * m[1] * m[2];
		mp1.clear();
		mp2.clear();
		mp2[2] = 1;
		for(int i = 2; i <= 1001; i ++)
		{
			for(int j = 0; j < 3; j ++)
				while(s[j] % i == 0)
					s[j] /= i, mp2[i] ++;
			for(int j = 0; j < 3; j ++)
				while(n[j] % i == 0)
					n[j] /= i, mp1[i] ++;
		}
		for(int j = 0; j < 3; j ++)
			if(s[j] > 1)
				mp2[s[j]] ++;
		for(int j = 0; j < 3; j ++)
			if(n[j] > 1)
				mp1[n[j]] ++;
		v.clear();
		ans = 0;
		vp.clear();
		for(mii::iterator it = mp2.begin(); it != mp2.end(); it ++)
			vp.push_back(make_pair(it -> X, it -> Y));
		for(mii::iterator it = mp1.begin(); it != mp1.end(); it ++)
			if(it -> Y > mp2[it -> X])
			{
				ll tmp = 1;
				for(int i = 1; i <= mp2[it -> X] + 1; i ++)
					tmp *= it -> X;
				v.push_back(tmp);
			}
		dfs(0, 1);
		for(int i = 0; i < (1 << v.size()); i ++)
		{
			ll now = M;
			bool flag = true;
			for(int j = 0; j < (int)v.size(); j ++)
				if((i >> j) & 1)
					now /= v[j], flag = !flag;
			if(flag) ans += now;
			else ans -= now;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}