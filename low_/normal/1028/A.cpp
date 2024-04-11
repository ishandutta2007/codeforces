#include<iostream>
#include<fstream>
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

int r=0, c=0;
int m, n;
char board[200][200];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>board[i][j];
	
	int cnt=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
	{
		if (board[i][j]=='B') 
		{
			cnt++;
			r+=i;
			c+=j;
		}
	}
	
//	cerr<<cnt<<"\n";
	cout<<r/cnt<<' '<<c/cnt;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: