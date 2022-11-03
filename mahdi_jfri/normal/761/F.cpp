#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;
const int maxk = 3e5 + 20;
const int maxs = 26 + 1;

string s[maxn];

int a[maxk] , b[maxk] , c[maxk] , d[maxk];
char ch[maxk];

int zarib[maxn][maxn][maxs];

ll sum[maxn][maxn][maxs] , S[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i];

		for(int j = 0; j < m; j++)
			s[i][j] -= 'a';
	}

	for(int i = 0; i < k; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> ch[i] , ch[i] -= 'a';

	for(int i = 0; i < k; i++)
		for(int j = ch[i]; j >= ch[i]; j--)
		{
			int val = -1;

			zarib[c[i]][d[i]][j] -= val;
			zarib[a[i] - 1][d[i]][j] += val;
			zarib[c[i]][b[i] - 1][j] += val;
			zarib[a[i] - 1][b[i] - 1][j] -= val;
		}

	for(int k = 0; k < maxs; k++)
		for(int i = n; i >= 1; i--)
			for(int j = m; j >= 1; j--)
				zarib[i][j][k] += zarib[i + 1][j][k] + zarib[i][j + 1][k] - zarib[i + 1][j + 1][k];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int s1 = 0 , chr = s[i - 1][j - 1];

			for(int k = 0; k < maxs; k++)
				s1 += zarib[i][j][k];

			zarib[i][j][chr] += k - s1;
		}

	for(int chr = 0; chr < maxs; chr++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				sum[i][j][chr] = zarib[i][j][chr] + sum[i - 1][j][chr] + sum[i][j - 1][chr] - sum[i - 1][j - 1][chr];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			for(int chr = 0; chr < maxs; chr++)
			{
				int val = (chr <= s[i - 1][j - 1]? 1 : -1);

				S[i][j] -= zarib[i][j][chr] * chr * val;
				S[i][j] += zarib[i][j][chr] * s[i - 1][j - 1] * val;
			}
			
			S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
		}

	ll res = 1e18;
	for(int i = 0; i < k; i++)
	{
		ll ans = 0;

		for(int chr = 0; chr < maxs; chr++)
		{
			int val = (chr <= ch[i]? 1 : -1);

			ll tmp = sum[c[i]][d[i]][chr];
			tmp -= sum[a[i] - 1][d[i]][chr];
			tmp -= sum[c[i]][b[i] - 1][chr];
			tmp += sum[a[i] - 1][b[i] - 1][chr];

			ans -= tmp * chr * val;
			ans += tmp * ch[i] * val;
		}

		ans += S[n][m];
		ans -= S[c[i]][d[i]];
		ans += S[a[i] - 1][d[i]];
		ans += S[c[i]][b[i] - 1];
		ans -= S[a[i] - 1][b[i] - 1];

		res = min(res , ans);
	}

	cout << res << endl;
}