// ensafan hoselam :(((

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 3e2 + 20;
const int maxm = 1e5 + 20;
const int mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const int base[2] = {737 , 4001};

int pw[maxm][2] , h[maxn][maxn][2] , a[maxn][2];

string s[maxn];

void prepare()
{
	pw[0][0] = pw[0][1] = 1;

	for(int i = 1; i < maxm; i++)
		for(int j = 0; j < 2; j++)
			pw[i][j] = 1LL * pw[i - 1][j] * base[j] % mod[j];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	prepare();

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i];

		for(auto ch : s[i])
			for(int j = 0; j < 2; j++)
				a[i][j] = (1LL * a[i][j] * base[j] + ch) % mod[j];
	}

	for(int l = 0; l < n; l++)
		for(int r = l; r < n; r++)
			for(int j = 0; j < 2; j++)
			{
				if(l == r)
					h[l][r][j] = a[l][j];
				else
					h[l][r][j] = (1LL * h[l][r - 1][j] * pw[s[r].size() + 1][j] + base[j] + a[r][j]) % mod[j];
			}

	int res = 0;

	for(int l = 0; l < n; l++)
		for(int r = l; r < n; r++)
		{
			int t = 1 , sum = 0;

			for(int i = l; i <= r; i++)
				sum += s[i].size();

			for(int i = r + 1; i + (r - l) < n; i++)
			{
				bool f = 1;
				for(int j = 0; j < 2; j++)
					if(h[i][i + (r - l)][j] != h[l][r][j])
						f = 0;

				if(f)
				{
					i = i + (r - l);
					t++;
				}
			}

			if(t > 1)
				res = max(res , (sum - 1) * t);
		}

	res = -res;
	for(int i = 0; i < n; i++)
		res += s[i].size();
	res += (n - 1);

	cout << res << endl;

}