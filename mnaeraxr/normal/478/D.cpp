#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << "=" << x << endl;
#define MP make_pair

typedef pair<int,int> pii;
typedef long long int64;

const int INF = 1 << 30;
const double EPS = 1e-9;

const int MOD = 1000000007;

const int MAXN = 200010;
int64 dp[2][MAXN];
bool ok[2][MAXN];

int R, G;



int64 solve()
{
	int cur = 0;
	dp[cur][0] = 1;
	ok[cur][0] = true;

	bool found = true;

	int64 maxh = 0;

	for(int i = 1; 1LL*i*(i+1)/2 <= R + G && found; i++)
	{
		cur ^= 1;
		found = false;
		maxh++;
		memset(dp[cur], 0, sizeof dp[cur]);
		for(int r = 0; r <= R; r++)
		{
			int g = i * (i+1) / 2 - r;
			if(r >= i)
			{
				dp[cur][r] += dp[cur^1][r-i];
				ok[cur][r] |= ok[cur^1][r-i];
			}
			if(g >= i)
			{
				dp[cur][r] += dp[cur^1][r];
				ok[cur][r] |= ok[cur^1][r];
			}
			dp[cur][r] %= MOD;

			if(ok[cur][r]) found = true;

//			DB(dp[cur][r]);
		}
	}
//	DB(found);
	if(!found)
	{
		cur = cur ^ 1;
		maxh--;
	}

//	DB(maxh);

	int64 ans = 0;
	for(int r = 0; r <= R; r++)
	{
		if(maxh * (maxh+1)/2 - r <= G)
		{
			ans += dp[cur][r];
			ans %= MOD;
		}
	}

	return ans;
}

int main()
{
	cin >> R >> G;
	cout<<solve()<<endl;
	return 0;
}