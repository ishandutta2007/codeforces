#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

char board[505][505];
int R, C, cor=true;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>R>>C;
//	vector<pair <int, int> > sheep;
	
	for (int i=0; i<505; i++) for (int j=0; j<505; j++) board[i][j]='.';
	
	for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) 
	{
		cin>>board[i][j];
//		if (board[i][j]=='S') sheep.push_back({i, j});
	}
	
	for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) if (board[i][j]=='S')
	{
		if (board[i+1][j]=='W' || board[i-1][j]=='W' || board[i][j+1]=='W' || board[i][j-1]=='W') 
		{
			cout<<"No";
			return 0;
		}
		
		if (board[i+1][j]=='.') board[i+1][j]='D';
		if (board[i-1][j]=='.') board[i-1][j]='D';
		if (board[i][j+1]=='.') board[i][j+1]='D';
		if (board[i][j-1]=='.') board[i][j-1]='D';
	}
	
	cout<<"Yes\n";
	for (int i=1; i<=R; i++) 
	{
		for (int j=1; j<=C; j++) cout<<board[i][j];
		cout<<"\n";
	}
}