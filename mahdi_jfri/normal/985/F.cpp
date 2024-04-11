#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxs = 26;
const int base = 4001 , mod = 1e9 + 7;

int h[maxn][maxs] , pw[maxn] , a[maxs] , b[maxs];

inline int get(int l , int r , int id)
{
	int ans = (1LL * h[r][id] - 1LL * h[l][id] * pw[r - l]) % mod;
	ans = (ans + mod) % mod;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = 1LL * pw[i - 1] * base % mod;

	int n , q;
	cin >> n >> q;

	string s;
	cin >> s;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < maxs; j++)
			h[i + 1][j] = (1LL * h[i][j] * base + (s[i] == 'a' + j)) % mod;

	while(q--)
	{
		int l1 , l2 , len;
		cin >> l1 >> l2 >> len;
		l1-- , l2--;

		for(int i = 0; i < maxs; i++)
		{
			a[i] = get(l1 , l1 + len , i);
			b[i] = get(l2 , l2 + len , i);
		}

		sort(a , a + maxs);
		sort(b , b + maxs);

		bool flag = 1;
		for(int i = 0; i < maxs; i++)
			if(a[i] != b[i])
				flag = 0;

		cout << (flag? "YES" : "NO") << endl;
	}
}