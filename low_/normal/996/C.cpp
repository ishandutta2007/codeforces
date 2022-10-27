#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int board[5][55], n, k;

bool check(int i, int j)
{
	if (i==2) if (board[2][j]==board[1][j]) return 1;
	if (i==3) if (board[3][j]==board[4][j]) return 1;
	return 0;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=4; i++) for (int j=1; j<=n; j++) cin>>board[i][j];
	
	vector <pair <int, pair <int, int> > > ans;
	int cars=k;
	for (int i=1; i<=n; i++) if (board[2][i]==board[1][i] && board[2][i]>0) 
	{
		ans.push_back({board[2][i], {1, i}});
		board[2][i]=0, cars--;
	}
	for (int i=1; i<=n; i++) if (board[3][i]==board[4][i] && board[3][i]>0) 
	{
		ans.push_back({board[3][i], {4, i}});
		board[3][i]=0, cars--;	
	}
	
	if (cars==2*n)
	{
		cout<<-1;
		return 0;
	}
	
	while (cars>0)
	{
		if (board[2][1]==0) if (board[3][1]>0)
		{
			board[2][1]=board[3][1];
			board[3][1]=0;
			ans.push_back({board[2][1], {2, 1}});
			if (check(2, 1)) 
			{
				ans.push_back({board[2][1], {1, 1}});
				board[2][1]=0;
				cars--;
			}
		}
		for (int i=1; i<n; i++) if (board[3][i]==0) if (board[3][i+1]>0)
		{
			board[3][i]=board[3][i+1];
			board[3][i+1]=0;
			ans.push_back({board[3][i], {3, i}});
			if (check(3, i)) 
			{
				ans.push_back({board[3][i], {4, i}});
				board[3][i]=0;
				cars--;
			}
		}
		if (board[3][n]==0) if (board[2][n]>0)
		{
			board[3][n]=board[2][n];
			board[2][n]=0;
			ans.push_back({board[3][n], {3, n}});
			if (check(3, n))
			{
				ans.push_back({board[3][n], {4, n}});
				board[3][n]=0;
				cars--;
			}
		}
		for (int i=n; i>1; i--) if (board[2][i]==0) if (board[2][i-1]>0)
		{
			board[2][i]=board[2][i-1];
			board[2][i-1]=0;
			ans.push_back({board[2][i], {2, i}});
			if (check(2, i))
			{
				ans.push_back({board[2][i], {1, i}});
				board[2][i]=0;
				cars--;
			}
		}
	}
	
	cout<<ans.size()<<"\n";
	for (int i=0; i<ans.size(); i++) cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<"\n";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: