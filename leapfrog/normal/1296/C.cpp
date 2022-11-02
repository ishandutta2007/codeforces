#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>

void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}

template <typename T,typename... Args> void read(T &t,Args &... args) {read(t); read(args...); }

int n,cnt[2][200005];
string s;
int sum[200005];
bool check()
{
	return !cnt[0] && !cnt[1];
}

bool cmp(pair<int,int> x,pair<int,int> y)
{
	if (x.first == y.first) return x.second > y.second;
	else return x.first < y.first;
}
map<pair<int,int>,int> mp;

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x = 0,y = 0;
		mp.clear();
		cin >> n;
		cin >> s;
		mp.insert(make_pair(make_pair(0,0),1));
		int ans = 0x7f7f7f7f7f7f7f,ansl = -1,ansr = -1;
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == 'U') x++;
			if (s[i - 1] == 'D') x--;
			if (s[i - 1] == 'L') y++;
			if (s[i - 1] == 'R') y--;
			if (mp.find(make_pair(x,y)) != mp.end())
			{
				if (i - mp[make_pair(x,y)] + 1 < ans)
				{
					ans = i - mp[make_pair(x,y)] + 1;
					ansl = mp[make_pair(x,y)];
					ansr = i;
				}
			}
			mp[make_pair(x,y)] = i + 1;
		}
		if (ansl == -1) puts("-1");
		else printf("%lld %lld\n",ansl,ansr);
	}
	return 0;
}