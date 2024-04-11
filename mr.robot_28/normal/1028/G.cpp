#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10000;
int dp[N][5][2], pos[N], pw[5] = {1};
int solve(int l, int tim, bool ask = false)
{
	if(tim == 0)
	{
		return l + 1;
	}
	if(l >= N)
	{
		if(ask)
		{
			cout << N;
			for(int i = 1; i <= N; i++)
			{
				cout << " " << l + pw[tim - 1] * i;
			}
			cout << endl;
			int ret;
			cin >> ret;
			if(ret == -1)
			{
				exit(0);
			}
			solve(l + ret * pw[tim - 1], tim - 1, true);
		}
		return l + pw[tim];
	}
	if(dp[l][tim - 1][ask] > 0)
	{
		return dp[l][tim - 1][ask];
	}
	if(ask)
	{
		cout << l + 1;
		pos[0] = l;
	}
	int cur = solve(l, tim - 1);
	for(int i = 0; i <= l; i++)
	{
		if(ask)
		{
			pos[i + 1] = cur;
			cout << " " << cur;
		}
		cur = solve(cur, tim - 1);
	}
	if(ask)
	{
		cout << endl;
		int ret;
		cin >> ret;
		if(ret == -1)
		{
			exit(0);
		}
		solve(pos[ret], tim - 1, true);
	}
	return dp[l][tim - 1][ask] = cur;
}
signed main(){
	for(int i = 1; i < 5; i++)
	{
		pw[i] = pw[i - 1] * 10001;
	}
	solve(0, 5, true);
	return 0;
}