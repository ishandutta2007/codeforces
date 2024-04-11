/*
	Author:	MarX
	School:	UH
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef long long int64;
typedef pair<int,int> pii;

const int oo = 1 << 30;
const double EPS = 1e-7;			
const int MAXN = 5000 + 10;

int64 L[MAXN];
int64 dp[MAXN][MAXN];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> L[i];
		L[i] += L[i - 1];
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (i >= M)
				dp[i][j] = max(dp[i][j],dp[i - M][j - 1] + L[i] - L[i - M]);
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}