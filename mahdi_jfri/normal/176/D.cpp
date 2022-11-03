#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = (1<<11);
const int maxs = 27;

string s[maxn];
vector<int> NextIn[maxn][maxs];

int NextOut[maxn][maxs] , First[maxn][maxs] , a[maxn];

pair<int , int> dp[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(First , 63 , sizeof First);
	memset(NextOut , 63 , sizeof NextOut);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		int m = s[i].size();

		for(int ch = 0; ch < maxs; ch++)
			NextIn[i][ch].resize(m);

		for(int j = m - 1; j >= 0; j--)
			for(int ch = 0; ch < maxs; ch++)
			{
				if(j + 1 < m && s[i][j + 1] == ch + 'a')
					NextIn[i][ch][j] = j + 1;
				else if(j + 1 < m)
					NextIn[i][ch][j] = NextIn[i][ch][j + 1];	
				else
					NextIn[i][ch][j] = 1e9;
			}

		for(int j = m - 1; j >= 0; j--)
			First[i][s[i][j] - 'a'] = j;
	}

	int m;
	cin >> m;

	for(int i = 0; i < m; i++)
		cin >> a[i] , a[i]--;

	for(int i = m - 1; i >= 0; i--)
		for(int ch = 0; ch < maxs; ch++)
		{
			if(i + 1 < m && First[a[i + 1]][ch] < 1e7)
				NextOut[i][ch] = i + 1;
			else
				NextOut[i][ch] = NextOut[i + 1][ch];
		}

	string t;
	cin >> t;
	int k = t.size();

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			dp[i][j] = {1e9 , 1e9};

	dp[0][0] = {0 , -1};
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= k; j++)
		{
			int ch = t[i - 1] - 'a';

			dp[i][j] = dp[i - 1][j];

			if(!j)
				continue;

			auto tmp = dp[i - 1][j - 1];

			if(tmp.first >= m)
				continue;

			int ind = a[tmp.first];

			if(tmp.second == -1 && First[ind][ch] < 1e7)
				dp[i][j] = min(dp[i][j] , make_pair(tmp.first , First[ind][ch]));

			else if(tmp.second != -1 && NextIn[ind][ch][tmp.second] < 1e7)
				dp[i][j] = min(dp[i][j] , make_pair(tmp.first , NextIn[ind][ch][tmp.second]));

			if(NextOut[tmp.first][ch] < m)
			{
				int pt = NextOut[tmp.first][ch];
				dp[i][j] = min(dp[i][j] , make_pair(pt , First[a[pt]][ch]));
			}

		}

	int ans = 0;
	while(ans + 1 <= k && dp[k][ans + 1].first < m)
		ans++;

	cout << ans << endl;

}