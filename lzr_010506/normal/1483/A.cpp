#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
map<int, int> mp;
int ans[500010];
vector<int> v[100010];
vector<pii> Id;
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		mp.clear();
		Id.clear();
		rep(i, 1, m) v[i].clear();
		rep(i, 1, m)
		{
			int k = read();
			Id.pb(make_pair(k, i));
			while(k --)
			{
				int x = read();
				v[i].pb(x);
			}
		}
		sort(Id.begin(), Id.end());
		rep0(i, sz(Id))
		{
			int j = Id[i].Y;
			int cnt = 100000000, id;
			rep0(k, sz(v[j]))
				if(mp[v[j][k]] < cnt) id = v[j][k], cnt = mp[v[j][k]];
			mp[id] ++;
			ans[j] = id;
		}
		bool flag = 0;
		for(auto x : mp)
		{
			//cout << x.Y << endl;
			if(x.Y > (m + 1) / 2){flag = 1; puts("NO"); break;}
		}
		if(!flag)
		{
			puts("YES");
			rep(i, 1, m) printf("%d ", ans[i]);
			puts("");
		}
	}

	return 0;
}