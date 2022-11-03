#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 15e4 + 20;

ll dp[2][maxn] , mx[maxn];

int a[maxn] , b[maxn] , t[maxn];

int main()
{
	int n , m , d;
	cin >> n >> m >> d;

	for(int i = 0; i < m; i++)
		cin >> a[i] >> b[i] >> t[i] , a[i]--;

	int last = t[m - 1];

	for(int i = m - 1; i >= 0; i--)
	{
		int x = i&1;
		int D = min((ll)n , 1LL * d * (last - t[i]));
		last = t[i];

		memset(dp[x] , 63 , sizeof dp[x]);
		memset(mx , 0 , sizeof mx);

		deque<int> dq;

		for(int j = n - 1; j >= 0; j--)
		{
			while(!dq.empty() && dp[!x][j] > dp[!x][dq.back()])
				dq.pop_back();
			dq.pb(j);
			
			if(dq.front() == j + D + 1)
				dq.pop_front();

			mx[j] = dp[!x][dq.front()];
		}

		for(int j = 0; j < n; j++)
			dp[x][j] = max(mx[j] , mx[max(0 , j - D)]);

		for(int j = 0; j < n; j++)
			dp[x][j] += b[i] - abs(a[i] - j);
	}

	cout << *max_element(dp[0] , dp[0] + n) << endl;
}