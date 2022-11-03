#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 20;

int g[maxb][maxn] , pw[maxn] , a[maxn] , n;

map<int , ll> mp;

inline int get(int l , int r)
{
	int id = pw[r - l + 1];

	return __gcd(g[id][l] , g[id][r - (1 << id) + 1]);
}

inline int solve(int p , int k)
{
	int l = p , r = n;

	while(r - l > 1)
	{
		int m = (l + r) / 2;

		if(get(p , m) >= k)
			l = m;
		else
			r = m;
	}

	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < maxb; i++)
		pw[(1 << i)] = i;

	for(int i = 1; i < maxn; i++)
		if(!pw[i])
			pw[i] = pw[i - 1];

	for(int i = 0; i < n; i++)
		g[0][i] = a[i];

	for(int i = 1; i < maxb; i++)
		for(int j = 0; j < n; j++)
		{
			if(j + (1 << (i - 1)) > n)
				g[i][j] = g[i - 1][j];
			else
				g[i][j] = __gcd(g[i - 1][j] , g[i - 1][j + (1 << (i - 1))]);
		}

	for(int i = 0; i < n; i++)
	{
		int last = i;

		while(last < n)
		{
			int k = get(i , last);
			
			int tmp = solve(i , k);
			mp[k] += tmp - last;

			last = tmp;
		}
	}

	int q;
	cin >> q;

	while(q--)
	{
		int x;
		cin >> x;

		cout << mp[x] << endl;
	}

}